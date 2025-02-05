# shop/management/commands/populate_db.py
from django.core.management.base import BaseCommand
from shop.models import Product, Order

class Command(BaseCommand):
    help = 'Populates the database with sample data'

    def handle(self, *args, **kwargs):
        # Create sample products
        products = [
            Product.objects.create(name='Laptop', price=1200.00),
            Product.objects.create(name='Smartphone', price=800.00),
            Product.objects.create(name='Headphones', price=200.00),
            Product.objects.create(name='Mouse', price=50.00),
            Product.objects.create(name='Keyboard', price=100.00),
        ]

        # Create sample orders
        order1 = Order.objects.create()
        order1.products.add(products[0], products[1])

        order2 = Order.objects.create()
        order2.products.add(products[2], products[3])

        order3 = Order.objects.create()
        order3.products.add(products[0], products[4])

        self.stdout.write(self.style.SUCCESS('Database populated successfully!'))
