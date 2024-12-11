// app/front/static/front/hub.js

import { POST_JSON, GET_FETCH } from "./api.js";
import { endpoints } from "./utils/utils.js";

document.addEventListener("DOMContentLoaded", () => {
    // Initialiser les modals Bootstrap
    const createGameModal = new bootstrap.Modal(document.getElementById('createGameModal'));
    const createTournamentModal = new bootstrap.Modal(document.getElementById('createTournamentModal'));

    // Boutons pour ouvrir les modals
    document.getElementById('create_game_btn').addEventListener('click', () => {
        createGameModal.show();
    });

    document.getElementById('create_tournament_btn').addEventListener('click', () => {
        createTournamentModal.show();
    });

    // Formulaire de création de jeu
    document.getElementById('create_game_form').addEventListener('submit', async (e) => {
        e.preventDefault();
        const gameName = document.getElementById('game_name').value.trim();
        const gameType = document.getElementById('game_type').value;

        if (gameName === "" || !gameType) {
            alert("Please specify all the fields.");
            return;
        }

        const data = {
            name: gameName,
            game_type: gameType,
            rounds_needed: gameRounds
        };

        const response = await POST_JSON(data, endpoints.game);
        if (response && response.success) {
            alert("Game created !");
            createGameModal.hide();
            fetchTournaments();
            fetchScheduledGames();
        } else {
            alert("Error while creating the game.");
        }
    });

    // Formulaire de création de tournoi
    document.getElementById('create_tournament_form').addEventListener('submit', async (e) => {
        e.preventDefault();
        const tournamentName = document.getElementById('tournament_name').value.trim();
        const tournamentGame = document.getElementById('tournament_game').value;
        const tournamentDate = document.getElementById('tournament_date').value;

        if (tournamentName === "" || !tournamentGame || !tournamentDate) {
            alert("Please specify all the fields.");
            return;
        }

        const data = {
            name: tournamentName,
            game: tournamentGame,
            date: tournamentDate
        };

        const response = await POST_JSON(data, endpoints.tournaments);
        if (response && response.success) {
            alert("Tournament created !");
            createTournamentModal.hide();
            fetchTournaments();
            fetchScheduledGames();
        } else {
            alert("Error while creating the tournament.");
        }
    });

    // Fonction pour récupérer et afficher les tournois
    async function fetchTournaments() {
        const list = document.getElementById('tournaments_list');
        list.innerHTML = '';
        const response = await GET_FETCH(endpoints.tournaments);  // Assurez-vous d'avoir cet endpoint
        if (response && response.tournaments) {
            response.tournaments.forEach(tournament => {
                const item = document.createElement('li');
                item.className = 'list-group-item d-flex justify-content-between align-items-center';
                item.textContent = `${tournament.name} - ${new Date(tournament.date).toLocaleString()}`;
                
                const joinBtn = document.createElement('button');
                joinBtn.className = 'btn btn-primary btn-sm';
                joinBtn.textContent = 'Join';
                joinBtn.addEventListener('click', () => joinTournament(tournament.id));

                item.appendChild(joinBtn);
                list.appendChild(item);
            });
        }
    }

    // Fonction pour récupérer et afficher les jeux programmés
    async function fetchScheduledGames() {
        const list = document.getElementById('scheduled_games_list');
        list.innerHTML = '';
        const response = await GET_FETCH(endpoints.games);  // Assurez-vous d'avoir cet endpoint
        if (response && response.games) {
            response.games.forEach(game => {
                const item = document.createElement('li');
                item.className = 'list-group-item d-flex justify-content-between align-items-center';
                item.textContent = `${game.name} - ${new Date(game.scheduled_at).toLocaleString()}`;
                
                const joinBtn = document.createElement('button');
                joinBtn.className = 'btn btn-primary btn-sm';
                joinBtn.textContent = 'Join';
                joinBtn.addEventListener('click', () => joinGame(game.id));

                item.appendChild(joinBtn);
                list.appendChild(item);
            });
        }
    }

    // Fonction pour rejoindre un tournoi
    async function joinTournament(tournamentId) {
        const response = await POST_JSON({}, `${endpoints.joinTournament}/${tournamentId}/`);  // Assurez-vous d'avoir cet endpoint
        if (response && response.success) {
            alert("You are now a participant of this tournament !");
            fetchTournaments();
            fetchScheduledGames();
        } else {
            alert("Error while joining the tournament");
        }
    }

    // Fonction pour rejoindre un jeu
    // Rejoindre un jeu

	
	async function joinGame(gameId) {
		const defaultHeaders = {
			'Content-Type': 'application/json',
			'Authorization': `Bearer ${localStorage.getItem('token')}`, // Exemple d'extraction du token
		};

		const response = await fetch(endpoints.joinGame(gameId), {
			method: 'POST',
			headers: defaultHeaders,
			body: JSON.stringify(data),
		});
		const data = await response.json();
		if (response.ok) {
			console.log('Jeu rejoint avec succès', data);
		} else {
			console.error('Erreur:', data);
		}
	}


    // Initialiser la page en récupérant les données existantes
    fetchTournaments();
    fetchScheduledGames();
});
