Position BinarySearch(List L, ElementType X)
{
	
	//定义左边边界，右边边界，中间元素
	Position left = 1;
	Position right = L->Last;
	Position mid;
	//先判断两个端点和中间情况
	if(X == L->Data[left]) return left;
	else if(X== L->Data[right]) return L->Last; 
	while(left <= right)
	{
		mid = (left + right)/2;
		if(X < L->Data[mid]) right = mid - 1;	/*调整右边边界*/
		else if(X > L->Data[mid])	left = mid + 1;	/*调整左边边界*/
		else return mid;	
	} 
	return NotFound;
}
