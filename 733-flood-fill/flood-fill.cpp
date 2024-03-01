class Solution {
public:

    void helper(vector<vector<int>>& image, int i, int j, int startColor, int color){
        
        int m = image.size();
        int n = image[0].size();

        if(i<0 || j<0 || i>m-1 || j>n-1 || image[i][j]!=startColor) return;

        image[i][j] = color;
        helper(image, i+1, j, startColor, color);
        helper(image, i, j+1, startColor, color);
        helper(image, i-1, j, startColor, color);
        helper(image, i, j-1, startColor, color);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        helper(image, sr, sc, image[sr][sc], color);
        return image;
    }
};