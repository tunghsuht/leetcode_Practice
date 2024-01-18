// class Solution {
// public:
//     int maxArea(vector<int>& height) {
        
//         int start = 0;
//         int end=1;


//         int max_water = (end-start)*min(height[start], height[end]);
//         int right = start;
//         end = end+1;
//         for(end=end; end<height.size(); end++){
//             if(height[end]!=0){
//                 int new_water = (end-right)*min(height[right], height[end]);
//                 max_water = max(new_water, max_water);

//                 start++;
//                 int start_plus_water = (end-start)*min(height[start], height[end]);
//                 if(start_plus_water >= max_water ){ //start+1~end的水量最大 則start往前移
//                     right = start;
//                     max_water = (end-right)*min(height[right], height[end]); //更新最大水量
//                 }
//             }
//         }
//         return max_water;
//     }
// };

//上面測資部分沒過 因為會有中間line大 但被省略的問題
//line的寬度對面積影響大! 接下來，需要決定如何移動指針，以尋找可能更大的面積。
//如果移動高度較大的線，容器的寬度會變小，這可能會減少容器的高度，從而降低面積。因此，選擇移動高度較小的線，以看看是否可以找到更高的線，從而增加容器的高度。
class Solution {
public:
    int maxArea(vector<int>& height) {


        int left =0;
        int end = height.size()-1;
        int max_area = 0;
        while(left<end){
            int new_area = (end-left)*min(height[left], height[end]);
            max_area = max(new_area, max_area);

            if(height[left]<height[end]){
                left++;
            }
            else{
                end--;
            }
        }return max_area;
    }
};
