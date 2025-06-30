// Add this to your script.js
function createRPSGame() {
    const choices = ['✊ Rock', '✋ Paper', '✌️ Scissors'];
    let playerScore = 0;
    let computerScore = 0;
    
    function computerPlay() {
        return Math.floor(Math.random() * 3);
    }
    
    function playRound(playerSelection) {
        const computerSelection = computerPlay();
        const result = document.getElementById('rps-result');
        
        if (playerSelection === computerSelection) {
            result.textContent = `Tie! Both chose ${choices[playerSelection]}`;
        } else if (
            (playerSelection === 0 && computerSelection === 2) ||
            (playerSelection === 1 && computerSelection === 0) ||
            (playerSelection === 2 && computerSelection === 1)
        ) {
            playerScore++;
            result.textContent = `You Win! ${choices[playerSelection]} beats ${choices[computerSelection]}`;
        } else {
            computerScore++;
            result.textContent = `You Lose! ${choices[computerSelection]} beats ${choices[playerSelection]}`;
        }
        
        document.getElementById('rps-score').textContent = 
            `You: ${playerScore} | Computer: ${computerScore}`;
    }
    
    return { playRound };
}

const rpsGame = createRPSGame();

document.querySelectorAll('.rps-btn').forEach(btn => {
    btn.addEventListener('click', (e) => {
        rpsGame.playRound(parseInt(e.target.dataset.choice));
    });
});