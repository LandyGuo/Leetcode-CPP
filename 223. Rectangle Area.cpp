/*
223. Rectangle Area   My Submissions QuestionEditorial Solution
Total Accepted: 35325 Total Submissions: 118563 Difficulty: Easy
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int S  =abs(C-A)*abs(B-D)+abs(G-E)*abs(H-F);
        if(C<E||B>H||D<F||A>G)//不相交的情形
            return S;
        //除此之外，一定相交
        int overlap =  abs(min(C,G)-max(A,E))*abs(min(D,H)-max(B,F));
        return S-overlap;
    }
};
