-- �ڵ带 �Է��ϼ���
set @hour := -1;
SELECT (@hour := @hour + 1) as hour,
(select count(*) from animal_outs where hour(datetime) = @hour) as count
from animal_outs
where @hour < 23

/*
1. set�� ����
2. set�� �� ; ����
3. := �� = �����ϱ�
4. ��ȣ �� ġ��
*/ 
