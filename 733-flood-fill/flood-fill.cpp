class Solution {
public:

    bool canFlood(vector<vector<int>>& image, int i, int j, int startColor){
        int m = image.size();
        int n = image[0].size();
        if(i<0 || j<0 || i>m-1 || j>n-1) return false;

        return image[i][j]==startColor;
    }

    void helper(vector<vector<int>>& image, int i, int j, int startColor, int color){
        image[i][j] = color;

        if(canFlood(image, i+1, j, startColor)){
            image[i+1][j] = color;
            helper(image, i+1, j, startColor, color);
        }
        if(canFlood(image, i, j+1, startColor)){
            image[i][j+1] = color;
            helper(image, i, j+1, startColor, color);
        }

        if(canFlood(image, i-1, j, startColor)){
            image[i-1][j] = color;
            helper(image, i-1, j, startColor, color);
        }

        if(canFlood(image, i, j-1, startColor)){
            image[i][j-1] = color;
            helper(image, i, j-1, startColor, color);
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        helper(image, sr, sc, image[sr][sc], color);
        return image;
    }
};