- **Binary Tree Postorder Traversal (145)**
	- 要求不用递归实现后序遍历
	- 后序是left-right-root，那么首先用修正的前序root-right-left，然后reverse一下，变成left-right-root就行了，代码如下：

- **Factorial Trailing Zeroes(172)**
	- 给出整数n，求$n!$末尾的0的个数，要求在logarithmic时间内求解
	- 首先容易知道要出现0，只有$2 \times 5 =10$才行，而对于从$1,2,...,n$的这一系列的数，是2的倍数的数明显比5多，因此每一个5一定能找到一个2与之配对，换句话说，0的个数和5的个数一样多，下面只需要找出5的个数就行了，容易知道反复除以5就行，代码如下：

- **Container with most water(11)**
	- 给出一些列的隔板的高度，求问用哪两个隔板装水能装最多的水
	- 求解非常巧妙，左右分别向中间靠拢，指针记为left和right, 如果left的值比right的小，则left往中间移动一格，否则right往中间移动一格

- **Maximal Rectangle(85)**
	- 题目的要求是给出一个0-1矩阵，要求给出一个最大的矩形，使得矩形里面的所有值为1
	- 解法非常巧妙，从上往下扫描，维护三个数组**height**, **left**, **right**，分别存储每一列的信息，当迭代到第i行的时候，left表示从左往右最靠右的0的位置，初始为0；right表示从右往左最靠左的0的位置，初始为cLen+1，因此列的编码是(0, 1, 2, ..., cLen, cLen+1)，然后height存的就是当前单元从上往下连续的1的个数
	- 维护好了这些信息，那么每个单元格的面积就是
$$Area(j) = height(j)*(right(j) - left(j) - 1)$$
	- 值得注意的是，在更新left和right的时候，得查看上一迭代的时候height的值，如果是0，那么本层不受约束，如果是1，那么考虑到上下直接的连通，left的值不能小于旧的left值，right的值不能大于旧的right值

- **Regular Expression Matching(10)**
	- 这题难度比较大，就是普通的正则表达式匹配问题，即`*`和`.`，前者表示`*`前面的字符出现任意次，后者可以替代任何字符。
	- 用动态规划的思路做，设一个二维矩阵b[m+1][n+1]，其中m是string串的长度，n是pattern串的长度，然后b[i+1][j+1]代表的意义就是s[1..i]和p[1..j]是否能匹配上
	- 有了上述的约定，首先置b[0][0]=true，然后再初始化第一行和第一第二列，接着利用递推关系进行求解。详细的递推请参考这儿[猛戳我](http://xiaohuiliucuriosity.blogspot.com/2014/12/regular-expression-matching.html)

- **Wildcard Matching(44)**
	- 这题相对于上面的正则匹配容易很多，只是通配符`*`和`?`匹配，但是leetcode平台对这题进行了专门的限制，最后给出了一个超长的测例，最终会RunTime Error。因此需要一种改进的贪心算法，非常高效，大致思想是如果遇到了`*`，那么先暂时记录位置，只使用一次，如果发现不行就再多使用一次

- **Binary Search Tree Iterator(173)**
	- 题目意思非常清楚，在O(1)的**平均**时间复杂度和O(h)的空间复杂度下从小到大输出一个二叉查找树
	- 这题的难点就在于要求O(h)的空间复杂度，因为直接能想到的方法是利用递归算法中序遍历一棵二叉查找树，并且用一个queue存起来。然后再依次输出，但是这样的空间复杂度是O(n)，不符合要求，因此需要另谋出路
	- 一种方法是维护两个栈path和aux，其中aux记录当前深度搜索过程中的所有节点。当要求输出下一个的元素的时候，只需要进入一个循环，循环内部每次从path中取出一个节点current，和aux的`top()`节点比，如果不相等，说明还没有到树的末端，于是依次把current的右节点，current本身和current的左节点压入path, 同时需要把current本身压入aux，表示current节点是当前深度优先搜索路径上的点。接着如果两个栈的`top()`元素相等，那好办，两个都弹出顶端节点，然后返回其值。
	- 另一种更加省空间的方法是，维护一个栈path，并且定义一个`pushAll`的函数，该函数的功能是把给定节点的所有左节点压入path。每次要求输出下一个节点的时候，取出path顶端的节点current，然后把调用`pushAll(current.right)`，并且返回current.val。
	- 以上两种方法，经过测试发现第二种更快，需要32ms，第二种仅仅需要31ms

- **Intersection of Two Linked Lists(160)**
	- 题目是在一个Y型的链表中，已知两个头指针的位置，问交汇的地方在哪儿，如果没有交汇点，则返回NULL，并且在程序返回的时候不能改变链表的结构，时间复杂度要求$O(n)$，空间复杂度要求$O(1)$
	- 这题虽然是easy题，但是思路非常难想到，一般都会想着如何标记信息，但是这题恰恰把这一条路给堵死。其实仔细想想，如果想要两个点相遇，只需要走的长度一样就行，这样我们就可以让首先达到终点的指针从**另一条链**从头开始，后到达的指针也从另一条链开始，这样两个指针将会同时到达交汇点

- **Implement strStr() (28)**
	- 题目要求给定两个字符串haystack和needle，找出haystack中第一次匹配上needle的下标，如果不存在，则直接返回-1
	- 这道题可以直接进行线性搜索，当needle的某一次匹配不成功的时候，需要回退到匹配上第一个字符时候的下标，并且加1重新开始匹配needle。直到达到末尾，或者匹配成功

- **Path Sum II(113)**
	- 这题其实题意就是找出所有从根节点到叶子节点的路径，使得路径上的节点值的和为给定的值。题目本来并不难，只需要深度优先遍历即可，但是坑就坑在有负值，因此一开始本来用栈+剪枝的方法，后来发现不好使，各种bug，还是乖乖用递归解决。

- **Word Ladder(127)**
	- 这题非常有趣，给出start word和end word，以及一个字典，要求每次变换一个字符，使得start word能转变成end word，并且变换中间的word都必须在字典中。这个最暴力的方法就是首先构造一个图，节点是合法的word，边是edit distance正好为1。然后在图上使用BFS就行了。但是这样容易LTE，因此思路需要转变
	- 一种可行的方法是从start word角度出发，对所有的可能做遍历，然后用字典进行筛选剪枝，每当发现一种合法的变换(必然是字典中的word)，那么立即把新word从字典中删除，并且push进队列。如此循环，直到到达end word。

- **Permutations I(46)**
	- 生成全排列，并且没有重复元素。这个比较好办，可以使用递归式，即
	$$P(a_1,...,a_n)=\{a_1, P(a_2,...,a_n)\} \cup ... \cup \{a_n, P(a_1,..., a_{n-1} \}$$
	- 设计函数`void recursion(int []num, int n, int len)`，其中n为遍历的位置，如果`n==len-1`，函数返回

- **Permutations II(47)**
	- 这题允许集合中出现重复，因此主要任务是如何去重。容易知道假设目前待交换的位置为`i`，并且此时正在`i<=j <=len-1`中对`j`进行遍历。在46题中，直接交换`num[i]`和`num[j]`是没有任何问题的，因为没有重复，但是在本题中首先如果`num[i]==num[j]`，则必然会产生重复；除此以外，如果存在`i<=k<=j-1`使得`num[k] == num[j]`，那么说明在遍历到`j`之前已经替换过和`num[j]`相等的`num[k]`了，这个时候也会产生重复。
	- 综上知道，只需要保证在`i<=k<=j-1`中没有元素满足`num[k]==num[j]`即可

- **Balanced Binary Tree(110)**
	- 这题本来非常简单，但是一开始概念混淆了，认为**平衡**的意思是对于每个节点，两棵子树的最大最小高度之差不能大于1，这样在递归调用的时候就得同时返回最大值和最小值，非常麻烦。但实际上的定义是高度不大于1即可，也就是最深的路径之间大小不大于1即可，这样在递归调用中就仅需要返回最大值即可。

- **Surrounded Regions(130)**
	- 这题类似围棋，给定一个width*height的棋盘，上面有`X`和`O`两种棋子，如果一个`O`的四个方向都被`X`包围，那么`O`变成`X`
	- 这题的思路就是找找到和边界相连通的所有`O`，然后把非连通的`O`给设置为`X`即可。具体实现方法是维护`bool`型的数组`visited`记录是否已经访问，并且维护一个队列，存放当前新发现的连通的`O`，这样，每次取出一个`O`，检查其**前后左右**四个方位的`O`棋子，如果未访问，则塞进队列。直到队列为空。

- **Palindrome Partition II(132)**
	- 这题就是找出给定字符串`s`中最小的切割次数，使得切出的字串都是回文。
	- 解题思路是用动态规划做，最快的方法是维护一个整型数组`mincut`，其中`mincut[i]`保存的是以`i`截止的最小切割数。更新过程，分为偶数更新和奇数更新
		- 奇数更新就是以下标`j`从头开始遍历，比较`i-j`和`i+j`的值，如果相等继续向两边扩展，并且令`cut[i+j+1] = min(cut[i+j+1],1+cut[i-j])`
		- 偶数更新同样以下标`j`从头开始遍历，比较`i-j+1`和`i+j`的值，如果相等继续向两边扩展，并且令`cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1])`
	- 非常简洁高效，当然，不是我想出来的....

- **Merge k Sorted Lists(23)**
	- 这题是**Merge Two Sorted Lists**的加强版，就是给定n个sorted lists，然后将他们串起来组成更长的sorted list。最直接的方法就是用优先队列，利用小根堆或者大根堆，但是发现效果不佳，61ms，可能是实现的原因。在网上一找发现更加高效的办法，而且不需要用优先队列，利用的就是两两合并的方法。具体来说，首先两两合并，然后把数量已经减半的lists继续两两合并，直到只剩下一个list。
	- 看起来遍历了很多遍，但是这种方法一个是实现起来快速，另一个隐含的加速的地方就是如果两两合并的时候某一个链表到了末端，那么只需要另一个链表把剩下的部分直接接到目标链表末端即可。

- **valid sudoku(36)**
	- 题目要求检查已给给定的数独是否是合理的，所谓合理就是每一行数字不同，每一列数字不同，每一个9宫格数字各不同。最直接的暴力方法是扫描，这样需要扫描的次数为$9*9*3=243$次，每次扫描用一个`unordered_set`来存储所有的遇到的数字，如果有重复立即返回false。
	- 另外一种非常快的方法是三种情况同时扫描，这样只需要对每个单元格访问一次即可，$9*9=81$次。此外，受到**基数排序**的启发，新建三个boolean型$9*9$的数组，每一列分别存储上述三种情况遇到的数字，由于数字范围是1-9，正好可以映射到下标0-8，一旦映射后发现数组对应单元格已经是true，说明产生了冲突。

- **Spiral Matrix I(54)**
	- 这题非常有意思，就是给定一个$m \times n$的矩阵，要求从最左上角开始，绕着矩阵顺时针依次打印，不能重复已经访问的元素，相当于绕一个内螺旋。大致的思路都是一样的，每次递减边界即可。但是实现上面有很多优化的地方，例如可以设置一个二维数组`int ops[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}`，这样每次就只需要做选择即可。

- **Spiral Matrix II(59)**
	- 属于54题的加强版，这次的输入是一个整数n，要求返回$n \times n$的方阵，其中方阵按螺旋顺序依次为$1, 2, ..., n^2$。这题思路其实和上题一致，但是不同的地方是首先得初始化矩阵，这样就方便后面的随机访问。

- **Subsets I(78)**
	- 给定一个没有重复的集合，求其所有的子集，并且打印的时候子集中的序列是单调递增的。显然有$2^n$个，循环生成即可，首先对给定集合排序，每次取一个元素，然后将原来的数组个数倍增，然后在新增的数组里里面添加新的元素即可。如此循环，直到到达末尾。

- **Subsets II(90)**
	- 这题是78题的加强版，不同之处是允许给定的集合有重复元素，这个时候思路和上述差不多，但是在对原始的所有数组进行遍历的时候，如果当前数组的最后一个元素和将要添加的元素一致，那么就果断直接添加，不进行扩增；如果不一致，那么策略与78一样，生成一个一模一样的数组，然后在新的数组末尾添加上新的元素。

- **Candy (135)**
	- 这题是分糖果的问题，一群小朋友排成一列，每个人有个rating值，要求rating值大的分的糖果要比**身边的孩子**多，注意没有约束如果rating值相同的情况，因此可以任意分配。题目的最终要求是以最少的糖果数满足所有的孩子，并且每个孩子至少分得一个糖果。
	- 一种非常简单的思路就是扫描三遍，首先从左往右扫描，处理好递增的情况；然后从右往左扫描，处理好递减的情况；最后遍历一遍数组把所有的值相加即可。这样一共需要扫描3遍，但是复杂度仍然是$\Theta(N)$
	- 另一种的思路就是发现，如果出现连续相同的rating，如$2,2,2,2$，那么实际上，我们可以拆分为三部分$..., 2 | 2, 2 | 2, ...$，中间的由于没有约束，因此全部取成1，然后左右两个子问题相互不相关，可以分别处理，并且，这两个子问题里面是肯定没有连续重复的rating的。因此，这种方法一共需要扫描2遍数组，第一遍拆分，第二遍对每个子问题求解。而每个子问题求解的方法就是贪心算法，具体参加代码

- **Valid number(65)**
	- 这题非常蛋疼，就是判断一个给定的字符串是否为合法的数字，包括各种奇葩情况。主要的解题思路就是用**有限状态机即可**，效率最高，唯一可以精简的就是状态的数量。详细请看代码

- **Reverse Integer(7)**
	- 这题要求把给定的32位有符号的整数进行反转输出，如`-123`输出`-321`，这里的关键是判断是否溢出，如`1000000003`反转后是会溢出的，因此需要找到一种高效判断溢出的方式。
	- 首先每次的更新是取`x`的余数`remainder`，然后`newReverse = 10 * reverse + remainder`进行更新即可，判断是否溢出可以通过简单的`(newReverse-remainder)/10==reverse`进行判断
	- 外层循环的退出条件是发现`x==0`

- **Reverse Bits(190)**
	- 这题和7有点类似，但是不同之处是整数变成了无符号数，并且要求按位对这32bits进行反转，因此外层循环必须要执行32次才行，因为2进制数可能高位为0。直接的方法是把7直接改一改，就可以通过测例。
	- 但是有一种更为巧妙的方法，例如对`AB`进行反转，相当于先变换成`BA`，然后再依次对`B`和`A`内部进行反转，即$(AB)^T=B^TA^T$。而此时`B`和`A`变成了原始问题的子问题，规模缩小，于是利用分而治之的办法便可以各个击破。效率惊人，非常快，8ms，而之前方法需要10ms。

- **Min Stack(155)**
	- 这题要求实现一个栈，但是和普通的栈相比多了一个操作，返回当前栈中的最小元素。一开始想到的办法是维护两个栈，一个存数据`stack_data`，一个存当前的最小值`stack_min`，每`push()`一个新的值`x`，把`min(x, stack_min.top())`重新压入`stack_min`，每次`pop()`的话两个栈同步进行弹栈。这样做固然可以，但是17个测例的成绩是80ms，非常慢。
	- 后来仔细一想，其实没必要每来一个新元素就同步压栈，而是发现`x`**不比当前**`stack_min.top()`的值大的时候再压入`stack_min`，即`x<=stack_min.top()`。这样就能保证`stack_min`中的值是**不增**的，并且元素个数比以前的方法也小了很多，最后的成绩是66ms

- **Roman to Integer(13)**
	- 这题是12题的姊妹题，要求给定一个罗马数字字符串，转换为相应的十进制数字。思路并不难，设置变量`previous_value`, `current_value`和`total`。从左往右扫描
		- 如果`current_value <= previous_value`，那么直接`total+=current_value`
		- 否则，`total+=current_value - 2*previous_value`即可。
	- $O(n)$的复杂度

- **Number of 1 Bits(191)**
	- 题目本身不难，就是给定一个无符号的32位整数，统计1的个数。
		- 最直接的方法就是逐位统计，只需要32次循环即可
		- 稍微改进的方法是遍历的时候留意原始值的范围，例如输入的是`3`，那么只需要判断2位即可
		- 最变态的方法是利用位运算，思路是首先以2位为一组相加，然后4位位一组相加，以此类推，最后16位为一组相加，得到的值就是输出值。

- **Insert Interval(57)**
	- 题目给一系列不重合的区间，并且给定一个新的区间，要求将新的区间插入给定的一系列区间中，必要的时候进行区间的合并。
	- 求解思路其实不难，就是首先找出所有和新区间不相交的区间，依次加入到新的区间数组中；然后把与新区间相交的区间进行合并，并把合并后的结果插入新的区间数组中；最后把剩余的区间插入新的区间数组中即可。

- **Scramble String(87)**
	- 这题给定一个字符串，容易知道可以用一棵树来表示这棵字符串，对于任意一个非叶子节点，交换其两个结点可以得到新的字符串，那么称新得到的字符串为原始字符串的Scramble String。那么现在的问题是，如果给定两个字符串，判断他们是否互为Scramble String。
	- 暴力搜索的办法就是每次比较两个字符串中字符的频率数，如果相等则认为有可能是Scramble String；接着遍历所有的切分位置，分别将两个字符串切成两段**(s11, s12)**和**(s21, s22)**。递归判`isScramble(s11, s21) && isScramble(s12, s22)`和`isScramble(s11,s22) && isScramble(s12, s21)`，其中只要有一种情况值是真，那么原始的`isScramble(s1,s2)`就是真，否则返回假。这种方法的复杂度其实非常高，但是实际的效果却出奇的好
	- 第二种方法是三维动态规划，复杂度是$O(n^3)$，维护的主要是`res[i][j][n]`，代表的意思是s1和s2的起始位置分别是i和j, 然后长度是n, 判断这两个字符串是否是isScramble。这样就可以利用更短的已经解决的问题去求解更加长的问题。最后返回`res[0][0][len]`

- **Binary Tree maximum path sum(124)**
	- 这题颇有意思，是给定一棵二叉树，然后返回所有从结点到结点的路径中最大的路径和值，注意是有负数的，直观上肯定需要用递归，然后可以扫描一次解决问题。关键就是如何设计递归的返回值。
	- 从最优解出发思考，最优解的组成要么就是所有点都在不同的层，即自上而下一条链，要么就是存在两个结点在同一层，即出现一个折线，无论是哪一种情况，总可以找到这个最优解的根。这里所谓的根就是链离树根最近的结点或者折线的拐点。这样，我们在搜索树的时候，就可以把当前遍历的点看做根，然后比较**经过根的路径**和**不经过根的路径**，而容易知道在当前结点看来**不经过根的路径**肯定是更低层的某个结点的**经过根的路径**，因此问题转换为找出所有经过根的路径的最大值。
	- 据此，设计了递归函数`max_to_bottom(TreeNode *current_node, int &max_seen_value)`。当递归到某个结点时，分别对其左右子树调用`max_to_bottom`，然后计算`go_through_value=left+current+right`计算出经过当前结点的最优路径，并且和`max_seen_value`比较并对`max_seen_value`进行更新。
	- 这样，就只需要扫描一遍树，树的根节点只需要取当前结点的`go_through_value`和`max_seen_value`中的较大值返回，问题即可得到解决。
	- 实现的细节请参看源码

- **String to Integer(8)**
	- 这题就是实现**aoti**，有许多细节需要注意，第一个就是开头有空白，第二个就是可能有符号位，接着就是字符串一旦出现了除了0-9之外的数字，那么认为截断，最后需要妥当处理的就是溢出问题了。
	- 解题思路是首先去掉所有的空白，然后记录符号位，接着利用`y = 10 * x + c`的方法更新，对于溢出的处理，目前所知最精简的处理方法就是` x > INT_MAX/10 || (x == INT_MAX/10 && c > 7)`。最后根据符号位进行适当的返回即可。

- **Merge Sorted Array(88)**
	- 这题就是要把两个排好序的数组合并成更大的数组，其实思路很简单，不需要从左往右进行排序，而是**从右往左**，扫描一遍即可，详细请看代码

- **Interleaving String(42)**
	- 这题给定三个字符串**s1**, **s2**和**s3**，问s3能否通过s1和s2交叉组合在一起，这里所谓交叉组合就是两个串的字符进行交错插入，生成新的长度为**len1+len2**的串。方法是用动态规划解决，利用2维表格，里面的每一个元素**(i,j)**代表s1的前i个字符和s2的前j个字符能否交叉组合成s3的前i+j个字符。由此不难看出，(i,j)为`true`有两种情况
		- 一种是相邻的同行左端元素为`true`，并且s2的**第j个**字符和s3的**第i+j**个字符一致
		- 另一种是相邻的同列上端的元素为`true`，并且s1的**第i个**字符和s3的**第i+j**个字符一致
	- 最终返回**(len1, len2)**即可，注意表格维度为`int[len1+1][len2+1]`，下标0代表空串
	- 由上述的动态规划我们得到一个重要的观察，就是只要存在一条通路从左上角到达右下角，那么原问题就是`true`，于是我们可以转换思路用**DFS来求解这道问题**。同样需要设置一个二维数组，这个时候0代表还未访问，1代表已经访问，从左上角开始分别向下和向右探索，倘若**下一个单元格没有访问并且可行**，那么递归调用下一个单元。任何时候到达了右下角，立即返回。
	- 上述DP和DFS算法的最坏复杂度一样，最后大概都是在5ms左右。理论上DFS会有微弱优势，因为DFS可能不需要访问所有单元格就可能找到解，而DP必须访问完所有单元格。

- **Trapping Rain Water(42)**
	- 这题非常形象，就是给定一个数组代表隔板的高度，每个隔板宽度都是1，问如果天上下雨的话，这个隔板系统最多能装多少雨。分析这个问题，对于每一个格子，究竟能装多少雨其实取决于这个格子**左边最高隔板**和**右边最高隔板**，其中比较小的隔板就是最终当前格子能装雨的最大高度。
	- 有了上述的重要观测，就可以设计一个朴素的**时间和空间都是O(n)**的算法了，设置一个`int`数组`peaks`，从左往右扫描一次，更新遇到的最大值，并用这个最大值填充相应的元素；然后从右往左也扫描一个更新`peaks`，这个时候`peaks`存的就是每个单元格理论上能装的最大高度的水，然后在逐个做差累加即可。
	- 除了上述算法，还有一个加强版算法**时间O(n), 空间O(1)**，主要思路是分别从两端向中间靠拢，假设i和j分别是左右两端的下标，选取`height[i]`和`height[j]`中比较小的进行更新，直到相遇。详细过程请参看代码。

- **Excel Sheet Column Title(168)**
	- 这题非常奇葩，引入了一套不含有0的计数系统，应用背景是Excel的编号，如`A-1`, `B-2`，....， `Z-26`，`AA-27`等等，要求把一个整数转换为字母表示的形式。由于不含有0，因此不能按常规的转换，不同的地方是每次`r = n % 26`和`n = n / 26`后，得判断`r`的取值，如果为0，说明除尽了，那么`n = n - 1`，否则按正常的`r + 'A' - 1`

- **Linked List Cycle II(142)**
	- 这题是典型的快慢指针问题，给一个链表，检测上面是否有环，如果有的话返回环开始的地方，否则返回`NULL`。只需要维护两个指针，慢指针一次前进1个单元，快指针一次前进2个单元，假设在**ptr**相遇，这个时候只需要重新设定两个指针分别从**ptr**和**head**同步前进，相遇的地方就是环开始的地方。

- **First Missing Positive(41)**
	- 这题简直太巧妙了，给定一个无序的整型数组，要求返回第一个缺失的正整数，并行时间复杂度要求$O(n)$，空间复杂度要求$O(1)$
	- 这题有个非常重要的观察，就是无论整数的范围如何，第一个缺失的正整数最大不超过$n+1$，其中$n$为元素的个数。有了这个重要的观察，那么我们就可以考虑把所有大于0并且不超过n的元素按次序放到对应的单元里面，这需要一次扫描。接着进行第二次扫描，从左往右，找出第一个错位的元素即可。

- **Reverse Linked List II (92)**
	- 这题要求把一个给定的链表从指定开始位置`m`到结束位置`n`翻转。一般来说需要特殊考虑`m=1`的情况，但是发现有种非常hack的方法是设置一个**虚拟**指针指向开头，有了这个作为保证，就可以不断地把`AB`交换为`BA`延伸下去，如`ABCD->BACD->CBAD->DCBA`，无需考虑边界条件，非常高效。

- **N-Queens II(52)**
	- 著名的N皇后问题，常规解法是**回溯法**，即深度优先搜索加上剪枝，值得注意的是实现上的一些小tricks，就是棋盘可以用一维数组表示，然后判断是否在对角线上可以用`abs(i-j) == abs(q[i] -q[j])`来快速判断
	- 后来上网一搜才发现还有更加变态的解法，就是用比特位与异或运算来求解，非常的巧妙，设置三个变量`row`，`left`和`right`，分别表示由于同一列，左对角线和右对角线的**禁位**，只要`row|left|right`就是所有的禁位，详细解法请参看源代码

- **Jump Game(55)**
	- 题意很简单，就是给定一个整型数组，表示每个元素能往前前进的最大步长，然后问是否可以从第一个元素开始到达最后一个元素。这题容易想复杂，其实只需要最远能到达末端元素即可，按照这样的思路，只需要维护一个变量`farthest`，表示目前已知的最远距离，然后扫描一遍即可，不断用`farthest = max(farthest, i+jump[i])`更新即可

- **Edit Distance(72)**
	- 编辑距离是一道典型的DP问题，就是求两个字符串`s1`和`s2`的最少编辑次数，包括删除，插入和替换
		- `s1`增加一个字符后和`s2`匹配
		- `s1`删除一个字符和`s2`匹配
		- `s1`和`s2`各删除一个字符然后观察最后一个字符是否可以进行替换
	- 于是我们可以得到公式`E(m, n)=min{1+E(i-1, j), 1+E(i, j-1), diff(i, j)+E(i-1, j-1)}`

- **Recover Binary Search Tree(99)**
	- 这题是将某个二叉搜索树的两个节点交换了位置，要求找出这两个节点。看似非常复杂，其实想明白后，就可以利用**中序遍历**的思想，如果在遍历过程中发现前一个节点比当前节点的值大，那么说明存在错位。这里关键需要分清楚的是有两种情况：
		- **相邻**，这个时候只需要交换这一前一后两个节点即可
		- **不相邻**， 这个时候交换错位的节点对的前一个节点，如`12345`变成了`14325`，错位的有`43`和`25`，此时交换`4`和`2`即可。

- **Partition List(86)**
	- 给定一个链表，如`1->4->3->2->5->2`，给定一个整数，如`x=3`，要求将链表按整数进行划分，并且保证相对位置，结果为`1->2->2->4->3->5`。
	- 解决方法是设置两个虚拟指针分别存储**大于x**和**不大于x**的元素，最后将其串起来即可

- **Maximum Gap(164)**
	- 给定一个无序的数组，要求找出按序拍好后的**最大间隔**
	- 有个非常重要的观察就是倘若数组的最小最大元素为`min`和`max`，数组长度为`len`，那么最大间隔至少为$bucketSize=\lceil (max-min) / (len-1) \rceil$，这样就可以按bucketSize的大小将元素划分若干bucket，个数为$bucketNum=\lceil (max-min)/bucketSize\rceil$。接着将所有元素映射到相应的桶内，存储每个桶内的最大值和最小值，然后扫描一遍所有桶，找出桶与桶之间的最大值即可。

- **Largest Number(179)**
	- 给定若干的数字，求如何组合这些数字使得生成的新的字符串数字数值最大。其实稍微抽象后知道就是个排序问题，比较$a_1a_2...a_mb_1b_2...b_n$和$b_1b_2...b_na_1a_2...a_m$即可

- **Longest Consecutive(128)**
	- 给定一个无序的整型数组，然后找出其中连续的最长序列，并且要求在$O(n)$的复杂度内完成。猛地一看没有太好的思路，但是考虑到人在找最长序列的时候，是首先观察一个数，然后向左向右扩展，看左右相邻的是否也在数组中，依次类推。因此在算法实现的时候可以利用HashMap的$O(1)$查找性能来实现。

- **Largest Rectangle in histogram(84)**
	- 给定一个整型数组，表示的是height高度，要求给出最大的矩形的面积。这题最直接的思路是对于每个元素，向左向右遍历，找到第一个比其小的元素，然后算出面积即可，但是时间复杂度是$O(n)$
	- 有种非常巧妙地利用栈的方法，每次遇到递增的元素，则把下标入栈，倘若栈为空也同样入栈；一旦遇到一个开始递减的元素，那么依次弹栈直到不比当前元素大，同时在每次弹栈的时候计算向右能围成的最大面积，更新max_area变量。具体的计算参看[这里](http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html)

- **3Sum(15)**
	- 这题是典型的面试题，给定一个无序整型数组，可能包含重复元素，要求找出所有和为0的三元数组，不能有重复。解法有两种：
	- 第一种是$O(n^2lgn)$，主要就是遍历i和j，求出$object = -(nums[i] + nums[j])$，然后用二分查找在剩余的元素中找，如果找到则true，否则就false
	- 第二种是$O(n^2)$的方法，固定一个元素`num[i]`，然后在剩余的元素中分别从头和尾向中间靠拢，使得和为`-num[i]`即可

- **Maximum Product Subarray(152)**
	- 这题是最大子数组和问题的衍生版本，只是将“和”换成了“乘积”， 最迅速的求解方式不变，都是想方设法扫描一次，存下**核心信息**， $O(n)$的复杂度
	- 核心的更新代码是`maxhere = max(max(max_pre*ele, min_pre*ele), ele)`和`minhere=min(min(max_pre*ele, min_pre*ele), ele)`。看似简单其实内涵大量的tricks。

- **Longest Substring Without repeating characters(3)**
	- 这题是给定字符串，然后返回最长的没有重复的子串。核心是用数组实现HashMap，用以记录是否出现，并且记录最近出现一次的下标值，初始值皆为`-1`
	- 有了这个信息，每遍历一个字符`c`，只需要查看是否在HashMap里面，如果出现了，那么取出最近出现的下标`idx=idxs[(int)c]`，更新起始下标`idx_begin=max(idx+1, idx_begin)`，注意这里能够处理`-1`的特殊情况。然后更新`max_length = max(max_legnth, i-idx_begin+1)`

- **Search in Rotated Sort Array I(33)**
	- 给定一个排好序的数组，但是从某个地方进行了对称旋转，如`[0,1,2,3,4,5]`绕`2`和`3`之间的空隙旋转为了`[3,4,5,0,1,2]`。然后问指定的元素`target`是否在数组中，另外没有重复元素。
	- 主要的思路就是二分查找，考虑`nums[mid]>nums[left]`决定是出于单调增的哪一边，然后常规做即可，最坏情况复杂度为$O(lgn)$

- **Search in Rotated Sort Array II(81)**
	- 放松约束允许出现重复元素，此时问题变得棘手，因为沿用I里面的判断的话可能出现`nums[mid]==nums[left]`的情况，这个时候索性就`left++`，但是这样最坏情况的复杂度就变成了$O(n)$了

- **Distinct Subsequences(115)**
	- 给定字符串S和T，问在S的子序列中出现T的distinct可能有多少种，例如`S=rabbbit`和`T=rabbit`，那么可以知道有3种。求解的方法是动态规划，核心的递推方程为倘若当前遍历的字符相等，则`A[i][j] = A[i-1][j] + A[i-1][j-1]`；如果不相等，则`A[i][j] = A[i-1][j]`。
	- 这里有个小技巧，就是更新的时候可以初始化一个长度为`t_len+1`的整型数组，初始化为0，第一个元素为1；然后从右往左更新，利用上述的迭代式。详情请看代码。

- **Binary Tree Inorder Traversal(94)**
	- 这题的难点在于只能用$O(1)$的空间和$O(n)$的时间，因此常规的栈递归以及栈辅助的方法都不奏效。细想一下，中序遍历最重要的是进入了左子树后如何能够返回到原来的分叉点，于是我们引入拆Morris的**线索二叉树**，核心思想就是把当前节点的前驱节点的`right`域指向当前节点即可，但是注意由于不能改动树的结构，因此在遍历完之后要修改回去。更详细的说明请看这儿[猛戳我](http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html)

- **Fraction to Recurring Decimal(166)**
	- 这题给定一个分子和分母，求分数值，如果有循环节，用括号将循环节括起来，如`1/6=0.1(6)`。初看非常难，要确定循环节的位置要涉及字符串的比较，但实际上，只需要用每次除法后的余数来标示即可，**只要余数相同则出现的循环节**。
	- 有了上面的思路，就可以利用`unordered_map`来存放所有的余数和对应的下标位置即可，一旦发现重复元素，那么添加括号返回即可。这里需要注意的是整型溢出的问题，解决方法非常暴力，上来先转化为`int64_t`类型，另外对于正负号也需要提前处理。

- **Sqrt(x)(69)**
	- 这题要求手动实现开方运算，输入输出都是int32的整型，因此最终结果需要截断，并不是四舍五入，因此可以利用位运算来实现
	- 首先`sqrt(x)`的最大值不超过16bit，于是可以设置最大值为`1<<16`，然后从高到低逐位试，看是否大于指定值`x`，如果大于指定值`x`则重置当前位。

- **Dungeon Game(174)**
	- 这题是伟大的骑士拯救公主的故事，骑士在初始时刻有一定的血量，每进入一个房间将损失或者增加一定的血量，然后问最少的血量是多少可以让骑士拯救公主？
	- 直觉上觉得是用动态规划来做，但是如果正向地贪婪地更新，最终是无法得到最优解的，正确的做法是逆向地更新，从后往前扫，设置新的数组`hp`，表示从当前位置到达最右下角遍所需要的最小HP数，当遍历到`hp[i][j]`的时候检查`hp[i+1][j]`和`hp[i][j+1]`，取最小后减去`dungeon[i][j]`，`need = min(hp[i+1][j], hp[i][j+1])-dungeon[i][j]`，接着`hp[i][j] = need <= 0 ? 1 : need`

- **Copy List with Random Pointers(138)**
	- 这题非常有意思，是给的一个链表，并且链表新增一个域random，要求复制这个链表。
	- 最基本的方法是用`unordered_map`，但是需要额外的空间，因此思考能不能不用额外的空间完成这个任务。解决方法就是3次遍历
		- 第一次在每个原始节点的next域后面接一个新的节点；
		- 第二次根据每个原始节点的random域对新节点的random域进行赋值；
		- 第三次将新链表脱离出来，详细过程参见源码

- **Suduko Slover(37)**
	- 给定一个数独，要求返回solution，类似于N皇后问题，是个典型的回溯题目，递归是比较好的选择，另外比较巧妙的可以利用`int row[9]`, `int col[9]`和`int cell[9]`来记录可选的，然后用`p = ~ban & (ban+1)`筛选出从右往左第一个非0的位置，详细方法见源码

- **Word Search II(212)**
	- 给定一个棋盘，每个方格内是字符，然后给定一个字符串数组，问哪些字符串在棋盘上出现了，所谓出现就是可以不重复的以水平垂直的连线串起来
	- 解决方法是首先对所有的字符串建立Trie树，然后依次对棋盘进行遍历，查看是否在Trie上

- **Lowest Common Ancestor(235)**
	- 给定一棵二叉树，并且给定两个节点`p`和`q`，求问高度最低的公共祖先节点。由于是二叉树，因此是有序的，故可以利用这个性质，从树根开始递归，依次检查`p`和`q`是否在树根的两端，那么返回当前树根；否则进入左侧或者右侧，取决于`p`和`q`落在哪一侧

- **Power of Two(231)**
	- 给定一个整数，判断是否为2的幂，这里有个非常tricky的方法，就是利用`n&(n-1)`，不难想象如果n为2的幂，那么`n&(n-1)`必为0，否则就不是2的幂。因此最终函数体就一句话`n > 0 && !(n&(n-1))`

- **Contains Duplicate III(220)**
	- 给定一个无序的数组，检查是否存在两个元素`num[i]`和`num[j]`，使得这两个元素的差值不超过`t`，并且下标`i`和`j`的差值不超过`k`
	- 这题的难点是如何快速判断数组中是否存在元素和新元素的差值不超过`t`，最暴力的当然是每来一个新元素都检查一遍前面的k个元素，但是这样效率实在太低。
	- 比较好的思路是利用**桶排序**的思想，设置大小为`t+1`的桶若干，对于每个新元素计算`long bucket_id = ((long)num[i] - INT_MIN) / (long(t) + 1)`，这里之所以要转化为long是因为可以溢出。得到了`bucket_id`之后，首先检查`m[bucket_id]`中是否有元素，如果有则返回true；接着检查`m[bucket_id+1]`或`m[bucket_id-1]`中的元素是否和`m[bucket_id+1]`的差值为t，如果是则返回true；这里为了约束下标范围k，可以通过保证`m`的大小不超过k即可

- **Longest Valid Parentheses(32)**
	- 给定一个只由`(`和`)`组成的字符串，判断里面最长的闭合的子串的长度，如`(()`是2，`()(())`是6
	- 比较暴力的做法是模拟人的求解过程，时间空间复杂度为$O(n)$
		- 一旦看到了`()`，则替换为数字`2`
		- 一旦看到了`(x)`，替换为数字`x+2`
		- 一旦看到了`xy`，替换为数字`x+y`
	- 另外一种是用动态规划的思路做，设置数组`int trace[]`记录从字符串开头到当前位置截止的闭合子串的长度，由于是闭合，因此当前位置`s[i]`必须为`)`，然后考察`s[i-1]`
	- 如果`s[i-1]=='('`，则直接闭合，`trace[i+1]=2+trace[i-1]`
	- 如果`s[i-1]==')'`，则检查内部长度`inner_len = trace[i]`,用`trace[i+1] = 2 + inner_len + trace[i-inner_len-1]`来更新

- **Shortest Palindrome(214)**
	- 这题感觉比较难，主要利用KMP算法中的构建`next`数组的算法，题目给定一个字符串如`aacecaaa`，允许在字符串前面添加若干字符使得整个字符串为palindrome，稍微转化一下，就相当于求`l=s+'#'+s.reverse()`的最长相同前后缀。主要是用DP算法，设置`trace`数组，第`i`个元素代表的意义是截止到当前字符的最长前后缀长度，如何利用`i`之前的信息来更新`trace[i]`是本题的难点和关键。
	- 设`j=trace[i]`，如果此时`l[j] == l[i]`，说明正好能进行扩展，那么`trace[i] = j+1`；否则，尝试更短的串，即令`j=trace[j-1]`，继续判断`l[j] ?= l[i]`，直到`j=0`或者找到`l[j] == l[i]`。

- **Longest Palindrome Substring(5)**
	- 回文的题目普遍有难度，这题是给定字符串，找出最长的回文子串，最暴力的方法就是逐个遍历，但是需要分奇偶，其实仔细一想，偶数本质上可以看成一个整体，也就是说，只需要合并重复的相邻字符，就变成奇数的情况了，因此只需要在暴力搜索的基础上稍微改进一点，增加**搜索相邻重复字符**的步骤，就可以一次性跳过大量的重复字符串，详细见源码。然后如果没有重复字符，那么相当于暴力搜索，但是内层循环很快跳出，因此最坏情况下是$O(n)$的复杂度
	- 第二种是利用动态规划的思路求解，假设`vector<int> trace`，其中第`i`个元素的意义是以当前字符为终止的所有子串，之所以要存所有的子串，而不是最长的子串，是因为在递推到`i+1`的时候可能匹配不上，却可能跟稍微短一点子串匹配上，而这个稍微短一点的子串可能在算法迭代到后面逐渐扩增成为最长的子串。因此需要保留较多的信息，最坏情况下是$O(n^2)$

- **Median of Two Sorted Arrays(4)**
	- 这题给定两个有序的数组，然后要求找出合并后数组的中位数，最笨的办法就是类似merge sort，逐个检查直到第k个元素，复杂度是$O(k)$，然而当k接近n的时候退化为$O(n)$。可以考虑不逐个检查，可以一次性检查$k/2$个，具体办法是取$j=k/2$, $i=k-i$，然后分别检查$a[i-1]$和$a[j-1]$，剔除小的一半。注意这里还有若干的corner case，若a为空，则直接返回`b[k-1]`即可，若b为空同理，此外若`k=1`，则返回`min(a[0], b[0])`

- **Jump Game II(45)**
	- 这题类似于小时候玩的跳格子，但是每个格子里写着下一步能跳到的最远距离，问到达最后一个格子的最小跳数。其实从拓扑上说这就是在一个图上跑BFS，因此常规的BFS遍历方法就能解决这题。然而这题和普通BFS不一样的地方是每个节点的出边下标是连续的，这一点给我们优化BFS提供了空间，每层BFS的时候只需要维护当前最远的节点下标即可，不需要用队列把所有的节点压入，详情见代码

- **Count Primes(204)**
	- 这题给定一个数字n，问小于n的所素数的个数，朴素的思想设置一个大小为`n`的布尔数组，记录当前位置是否为素数，初始状态全部为`false`。接着扫描一遍，一旦发现某个数$m$是素数，那么其$km$都是素数，注意这里的$k$可以从$m$，即$m^2$算起。

- **Unique Binary Search I(96)**
	- 给定$1 \cdots n$共`n`个数，返回合法的所有二叉搜索树的个数，容易知道这个可以用递归的方法，实际上是卡特兰数，因此只需要$O(n)$的空间和时间即可完成

- **Unique Binary Search II(95)**
	- 这题要求返回所有的二叉搜索树，同样可以用递归的方法，但是这次是用$T(n-1)$推导出$T(n)$，不难知道有两种情况，一种$T(n-1)$是第n个节点的左孩子，第二种就是对$T(n-1)$中的每个二叉搜索树，从根节点开始遍历，考察是否有右孩子，如果有，那么用新增的第n个节点替代，并且将原来的右孩子接到新增节点的左边，然后沿着右孩子迭代下去。详情见代码

- **Substring with Concatenation of all words(30)**
	- 这题给定一个字符串和一个字典，注意这里的字典可能包含重复的单词，因此不能用set来表示，需要统计每个单词出现的次数生成一个指纹`unordered_map<string, int>fp`。
	- 这题另外一个难点是需要考虑`word_length`中任意起始位置，因此在外层循环有$O(wl)$次，由于单词长度相同，因此在内层循环的时候每次考察一个单词，如果出现的次数大于`fp`中对应单词的次数，那么考虑要调整窗口的大小
	- 一旦出现了不是字典中的单词，那么窗口清空，直接往后移

- **Minimum Window Substring(76)**
	- 这题与30非常相似，不同的地方有两点，一个是允许至少出现字典中的单词及其频数，这意味着窗口内某个在字典中的单词可能出现非常多次，这也是合法的；另一个不同的地方是允许窗口内出现非字典中的单词
	- 只需要考虑清楚窗口左边界和右边界的更新的策略，并且利用`counter`记录当前窗口内的字符是否满足要求。具体来说，右边界的更新的自然增长，左边界的更新是一旦发现窗口左边界的字符出现频数比字典中大的时候，那么右移并且将窗口中对应字符的频数减一，另外当遇到非字典中的字符的时候窗口右边界也右移，具体参见代码。

- **Lowest Common Ancestor of a Binary Tree(236)**
	- 给定二叉树的两个节点，返回其公共祖先节点。这题可以直接用递归实现，值得注意的是，如果当前的值满足` root == p || root == q || root == NULL`那么直接返回`root`即可，否则分别递归调用左右子树，如果皆为非空，那么返回`root`，否则返回非空的一侧，如果都为空，那么返回`NULL`

- **Two Sum(1)**
	- 这题并不难，但是有一些坑，首先看到两个数相加就条件反射用了`3Sum`的方法，然后这题给定的数组并不是有序的，如果先排序的话复杂度至少就为$O(nlgn)$，其次这题要求返回的是下标，如果排序之后下标将会打乱，最终要么记录下标映射关系，要么重新花$O(n)$的的时间重新扫描一遍。
	- 其实这题只需要扫描一遍，中途用`unordered_map m`记录每个元素出现的下标即可，遍历到`nums[i]`的时候，首先判断`t = target - nums[i]`是否在`map`中，如果在的话就把`m[t]`和`i+1`依次返回。

- **Basic Calculator(224)**
	- 这题要求实现简单的计算器，但是只能做加减运算，另外允许出现括号。最普遍的方法是维护一个操作符栈和操作数栈，然后根据规则进行状态跳转。
	- 然后另外一个更加简单的思路是可以利用结合律去掉括号，而一旦去掉了括号，那么就可以按照顺序依次计算即可，具体方法是用一个栈来保存当前的符号，具体见代码。这种方法明显快许多

- **Multiply String(43)**
	- 这题其实就是大数的乘法，原理并不难，主要是实现有些技巧，两个`for`循环，设置数组`vector<int> ans`，内层循环设置变量`int carry`，表示是否需要进位，然后依次对应位置相乘并且累加`ans[k]`和`carry`，即
	- `sum = (n1 * n2 + carray  + ans[k]) 10`
	- `ans[k] = sum % 10`
	-  `carry = sum / 10`

- **Validate Binary Search Tree (98)**
	- 这题要求验证一个给定的二叉搜索树是否合法，最直接的思路就是递归对左右两个分支进行检查，注意这个时候需要引入最小和最大值变量；第二种思路就是直接中序遍历，看看是否是单调递增的序列

- **Bitwise AND of Numbers Range (201)**
	- 这题比较有意思，要求返回`[a,b]`区间内所有整数的按位取与的结果，其实就是找两个二进制数从左往右的最长公共序列，方法就是不断的右移一位，直到两个数字相等，记录此时的`offset`，然后再左移`offset`位即可

- **Repeated DNA Sequences(187)**
	- 这题给出一个DNA序列，要求返回所有的出现次数大于2的**10个字符**的序列。直接暴力的方法是用一个`unordered_map<string, int>`，但是这样会MLE， 于是想办法把字符串编码为`int`型，考虑到`ATGC`的末尾3位都是不一样的，因此直接用最后三位来表征这三个字符即可，于是原来的长度为10的`80bits`字符串可以用`int32`来唯一表示，直接缩小至少一半。

- **Add Digits(258)**
	- 这题其实非常常见，就是把一个给定的数的各个位数加起来，反复执行直到只剩下个数位，其实方法简单得出奇，` (x - 1) % 9  + 1`， 特殊考虑0的情况，返回0
