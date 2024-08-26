bool isPerfectSquare(int num)
{
    int i = 1, j = num;
		while(i <= j){
			int mid = i +(j - i) * 0.5;
			if(num % mid == 0 && mid == num / mid){ return true; }
			else if(mid < num / mid){ i= mid + 1; }
			else{ j= mid - 1; }
		}
		return false;   
}