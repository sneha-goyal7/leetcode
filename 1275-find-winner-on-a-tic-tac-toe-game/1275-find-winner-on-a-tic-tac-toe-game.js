/**
 * @param {number[][]} moves
 * @return {string}
 */
var tictactoe = function(moves) {
    const board = new Array(9).fill(0);

    // A = 1 (even index moves), B = 2 (odd index moves)
    for (let i = 0; i < moves.length; i++) {
        const [r, c] = moves[i];
        board[r * 3 + c] = i % 2 === 0 ? 1 : 2;
    }

    // 8 winning patterns: 3 rows, 3 columns, 2 diagonals
    const wins = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8], // rows
        [0, 3, 6], [1, 4, 7], [2, 5, 8], // columns
        [0, 4, 8], [2, 4, 6]             // diagonals
    ];

    for (const [a, b, c] of wins) {
        if (board[a] !== 0 && board[a] === board[b] && board[b] === board[c]) {
            return board[a] === 1 ? "A" : "B";
        }
    }

    return moves.length === 9 ? "Draw" : "Pending";
};