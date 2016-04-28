/*

292. Nim Game  
Difficulty: Easy
You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.

Hint:

If there are 5 stones in the heap, could you figure out a way to remove the stones such that you will always be the winner?
*/

/*2nd pass
只要剩下的n不为4的倍数，先手就一定能赢~
因此先手获胜的策略就是：每次拿让剩下的都为4的倍数（都为4的倍数时，后手一定会输）
当剩下的n为4的倍数，后手一定能赢~
因此后手获胜的策略就是：每次拿和前面的先手凑成4的倍数，这样剩下的n一定还是4的倍数，先手就始终没办法赢

*/
class Solution {
public:
    bool canWinNim(int n) {
        return n%4!=0;
    }
};
