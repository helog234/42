from django.test import TestCase, override_settings
from django.contrib.auth.models import User
from django.urls import reverse
from .models import Article, UserFavouriteArticle

@override_settings(LANGUAGE_CODE='en')
class ProtectedViewsTestCase(TestCase):
    def setUp(self):
        """Create a user and an article for all tests."""
        self.user = User.objects.create_user(username='testuser', password='password123')
        self.article = Article.objects.create(
            title='Test Article',
            content='Some content here',
            author=self.user
        )
        self.publication_url = reverse('blog:publication-list')
        self.favourite_list_url = reverse('blog:favourite-article-list')
        self.article_create_url = reverse('blog:article-create')

    def test_views_redirect_if_not_logged_in(self):
        """Test that protected views redirect unauthenticated users."""
        urls = [self.publication_url, self.favourite_list_url, self.article_create_url]
        for url in urls:
            with self.subTest(url=url):
                response = self.client.get(url)
                # Check that the redirection points to the login page
                self.assertRedirects(response, f"{reverse('blog:login')}?next={url}")

    def test_views_are_accessible_if_logged_in(self):
        """Test that protected views are accessible to logged-in users."""
        self.client.login(username='testuser', password='password123')
        urls = [self.publication_url, self.favourite_list_url, self.article_create_url]
        for url in urls:
            with self.subTest(url=url):
                response = self.client.get(url)
                self.assertEqual(response.status_code, 200)

@override_settings(LANGUAGE_CODE='en')
class RegisterViewTestCase(TestCase):
    def setUp(self):
        self.user = User.objects.create_user(username='testuser', password='password123')
        self.register_url = reverse('blog:register')

    def test_register_page_is_accessible_if_not_logged_in(self):
        """Test that the registration page is accessible to a visitor."""
        response = self.client.get(self.register_url)
        self.assertEqual(response.status_code, 200)
        self.assertTemplateUsed(response, 'blog/register.html')

    def test_register_page_redirects_if_logged_in(self):
        """Test that the registration page redirects a logged-in user."""
        self.client.login(username='testuser', password='password123')
        response = self.client.get(self.register_url)
        self.assertRedirects(response, reverse('blog:articles-list'))

@override_settings(LANGUAGE_CODE='en')
class FavouriteFunctionalityTestCase(TestCase):
    def setUp(self):
        self.user = User.objects.create_user(username='testuser', password='password123')
        self.article = Article.objects.create(
            title='Test Article',
            content='Some content here',
            author=self.user
        )
        self.add_favourite_url = reverse('blog:favourite-article', kwargs={'article_pk': self.article.pk})

    def test_cannot_add_favourite_if_not_logged_in(self):
        """Test that a visitor cannot add a favourite."""
        response = self.client.post(self.add_favourite_url)
        self.assertRedirects(response, f"{reverse('blog:login')}?next={self.add_favourite_url}")
        self.assertEqual(UserFavouriteArticle.objects.count(), 0)

    def test_can_add_favourite_once(self):
        """Test that a logged-in user can add a favourite."""
        self.client.login(username='testuser', password='password123')
        response = self.client.post(self.add_favourite_url)
        self.assertEqual(UserFavouriteArticle.objects.count(), 1)
        self.assertEqual(UserFavouriteArticle.objects.first().article, self.article)

    def test_cannot_add_same_favourite_twice(self):
        """Test that a logged-in user cannot add the same favourite twice."""
        self.client.login(username='testuser', password='password123')
        # Add the favourite the first time
        self.client.post(self.add_favourite_url)
        self.assertEqual(UserFavouriteArticle.objects.count(), 1)

        # Try to add it a second time
        self.client.post(self.add_favourite_url)
        # The number of favourites should not have changed
        self.assertEqual(UserFavouriteArticle.objects.count(), 1)
