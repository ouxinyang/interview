﻿时间复杂度:
最好的情况为O(n);
最坏的情况为O(n);
平均复杂度为O(n);
上诉三种情况下时间复杂度都相等的原因是都需要遍历一个url，得到每个key-value对。
空间复杂度:O(n)
内存泄露等问题:源程序缺少对空字符串的判断，需要修改。