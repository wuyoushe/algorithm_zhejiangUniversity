Position BinarySearch(List L, ElementType X)
{
	
	//������߽߱磬�ұ߽߱磬�м�Ԫ��
	Position left = 1;
	Position right = L->Last;
	Position mid;
	//���ж������˵���м����
	if(X == L->Data[left]) return left;
	else if(X== L->Data[right]) return L->Last; 
	while(left <= right)
	{
		mid = (left + right)/2;
		if(X < L->Data[mid]) right = mid - 1;	/*�����ұ߽߱�*/
		else if(X > L->Data[mid])	left = mid + 1;	/*������߽߱�*/
		else return mid;	
	} 
	return NotFound;
}
