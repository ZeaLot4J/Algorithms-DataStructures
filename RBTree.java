import java.util.Random;

public class RBTree<T extends Comparable<T>> {
    private RBNode<T> root;
    private static final boolean RED = false;
    private static final boolean BLACK = true;

    class RBNode<T extends Comparable<T>> {
	boolean color;
	T key;
	RBNode<T> left;
	RBNode<T> right;
	RBNode<T> parent;

	public RBNode(boolean color, T key, RBNode<T> left, RBNode<T> right, RBNode<T> parent) {
	    this.color = color;
	    this.key = key;
	    this.left = left;
	    this.right = right;
	    this.parent = parent;
	}
    }

    public static void main(String[] args) {
	RBTree<Integer> map = new RBTree<>();
	Random rd = new Random();
	long start = System.currentTimeMillis();
	for (int i = 0; i <= 10000000; i++) {
	    map.insert(rd.nextInt() * 100000);
	}
	long end = System.currentTimeMillis();
	// map.display();
	System.out.println(end - start);
    }

    private void leftRotate(RBNode<T> x) {
	RBNode<T> y = x.right;
	x.right = y.left;
	if (y.left != null)
	    y.left.parent = x;
	y.parent = x.parent;
	if (x.parent != null) {
	    if (x.parent.left == x)
		x.parent.left = y;
	    else
		x.parent.right = y;
	} else {
	    this.root = y;
	}
	y.left = x;
	x.parent = y;
    }

    private void rightRotate(RBNode<T> x) {
	RBNode<T> y = x.left;
	x.left = y.right;
	if (y.right != null)
	    y.right.parent = x;
	y.parent = x.parent;
	if (x.parent != null) {
	    if (x.parent.left == x)
		x.parent.left = y;
	    else
		x.parent.right = y;
	} else {
	    this.root = y;
	}
	y.right = x;
	x.parent = y;
    }

    private void insertNode(RBNode<T> node) {
	RBNode<T> curr = this.root, pre = null;
	int comp = 0;
	while (curr != null) {
	    pre = curr;
	    comp = node.key.compareTo(curr.key);
	    if (comp < 0)
		curr = curr.left;
	    else if (comp > 0)
		curr = curr.right;
	    else // 相等跳过
		return;
	}
	node.parent = pre;
	if (pre == null)
	    this.root = node;
	else {
	    if (comp < 0)
		pre.left = node;
	    else if (comp > 0)
		pre.right = node;
	}
	// node在创建时就被初始化为了红色
	insertFixup(node);
    }

    private void insertFixup(RBNode<T> node) {
	RBNode<T> parent, gparent, uncle;
	// 如果没有父结点，说明当前结点就是根
	// 如果父结点是黑的，那么插入一个红结点没有影响
	while ((parent = node.parent) != null && parent.color == RED) {
	    // 如果有父结点并且为红色，则肯定有祖父结点，因为根结点必须为黑色
	    gparent = parent.parent;

	    // 如果父结点是祖父的左孩子
	    if (parent == gparent.left) {
		// case1
		// 如果叔叔是红色，则把父结点和叔叔结点涂黑，祖父涂红
		if ((uncle = gparent.right) != null && uncle.color == RED) {
		    parent.color = BLACK;
		    uncle.color = BLACK;
		    gparent.color = RED;
		    node = gparent; // 再将祖父作为当前结点进一步操作
		    continue;
		}
		// 如果叔叔为null，也当作黑结点
		// case2 叔叔为黑，当前结点为父结点的右孩子，把父结点左旋
		if (parent.right == node) {
		    leftRotate(parent);
		    RBNode<T> tmp = parent;// 交换一下引用
		    parent = node;
		    node = tmp;
		}
		// case3 叔叔为黑，当前结点为父结点的左孩子，将父结点涂黑，祖父涂红，再右旋
		parent.color = BLACK;
		gparent.color = RED;
		rightRotate(gparent);
	    } else {// 如果父结点是祖父的右孩子，操作相反
		if ((uncle = gparent.left) != null && uncle.color == RED) {
		    parent.color = BLACK;
		    uncle.color = BLACK;
		    gparent.color = RED;
		    node = gparent;
		    continue;
		}

		if (parent.left == node) {
		    rightRotate(parent);
		    RBNode<T> tmp = parent;// 交换一下引用
		    parent = node;
		    node = tmp;
		}

		parent.color = BLACK;
		gparent.color = RED;
		leftRotate(gparent);
	    }
	}

	this.root.color = BLACK;
    }

    public void insert(T key) {
	// 直接初始化为红色
	RBNode<T> node = new RBNode<T>(RED, key, null, null, null);
	insertNode(node);
    }

    private void display(RBNode<T> curr) {
	if (curr != null) {
	    display(curr.left);
	    System.out.println(curr.key + "--" + (curr.color ? "BLACK" : "RED"));
	    display(curr.right);
	}

    }

    public void display() {
	display(this.root);
    }

    private RBNode<T> searchNode(T key) {
	RBNode<T> curr = this.root;
	while (curr != null) {
	    if (key.compareTo(curr.key) < 0)
		curr = curr.left;
	    else if (key.compareTo(curr.key) > 0)
		curr = curr.right;
	    else
		return curr;
	}
	return curr;
    }

    /**
     * 
     * @param node
     *            待删除结点
     */
    private void deleteNode(RBNode<T> node) {
	// 删除之后顶替上来的结点
	RBNode<T> replace = null, parent = null;
	// 如果删除的结点左右孩子都有
	if (node.left != null && node.right != null) {
	    RBNode<T> succ = null;
	    for (succ = node.right; succ.left != null; succ = succ.left)
		;
	    node.key = succ.key;
	    deleteNode(succ);
	    return;
	} else {// 叶子或只有一个孩子的情况可以合并成一种
		// 如果删除的是根，则root指向其孩子(有一个红孩子或者为nil)
	    if (node.parent == null) {
		// 如果有左孩子，那根就指向左孩子，没有则指向右孩子（可能有或者为NIL）
		this.root = (node.left != null ? node.left : node.right);
		replace = this.root;
		if (this.root != null)
		    this.root.parent = null;
	    } else {// 非根情况
		RBNode<T> child = (node.left != null ? node.left : node.right);
		if (node.parent.left == node)
		    node.parent.left = child;
		else
		    node.parent.right = child;

		if (child != null)
		    child.parent = node.parent;
		replace = child;
		parent = node.parent;
	    }
	}

	if (node.color == BLACK)
	    deleteFixUp(replace, parent);

    }

    private void deleteFixUp(RBNode<T> replace, RBNode<T> parent) {
	// 这个方法基于分支已经少了一个黑结点的情况

	RBNode<T> brother = null;
	// 如果顶替结点是黑色结点，并且不是根结点，这里面parent是一定不为null的
	while ((replace == null || replace.color == BLACK) && replace != this.root) {
	    if (parent.left == replace) {
		brother = parent.right;
		// case1 红兄，brother涂黑，parent涂红，parent左旋，replace的兄弟改变了，变成了黑兄的情况
		if (brother.color == RED) {
		    brother.color = BLACK;
		    parent.color = RED;
		    leftRotate(parent);
		    brother = parent.right;
		}
		// 经过上面，不管进没进if，兄弟都成了黑色
		// case2 黑兄，且兄弟的两个孩子都为黑
		if ((brother.left == null || brother.left.color == BLACK) && (brother.right == null || brother.right.color == BLACK)) {
		    // 如果parent此时为红，则把brother的黑色转移到parent上
		    if (parent.color == RED) {
			parent.color = BLACK;
			brother.color = RED;
			break;
		    } else {// 如果此时parent为黑，即此时全黑了，则把brother涂红，导致brother分支少一个黑，使整个分支都少了一个黑，需要对parent又进行一轮调整
			brother.color = RED;
			replace = parent;
			parent = replace.parent;
		    }
		} else {
		    // case3 黑兄，兄弟的左孩子为红色，右孩子随意
		    if (brother.left != null && brother.left.color == RED) {
			brother.left.color = parent.color;
			parent.color = BLACK;
			rightRotate(brother);
			leftRotate(parent);
			// case4 黑兄，兄弟的右孩子为红色，左孩子随意
		    } else if (brother.right != null && brother.right.color == RED) {
			brother.color = parent.color;
			parent.color = BLACK;
			brother.right.color = BLACK;
			leftRotate(parent);
		    }

		    break;
		}

	    } else {
		brother = parent.left;
		// case1 红兄，brother涂黑，parent涂红，parent左旋，replace的兄弟改变了，变成了黑兄的情况
		if (brother.color == RED) {
		    brother.color = BLACK;
		    parent.color = RED;
		    rightRotate(parent);
		    brother = parent.left;
		}
		// 经过上面，不管进没进if，兄弟都成了黑色
		// case2 黑兄，且兄弟的两个孩子都为黑
		if ((brother.left == null || brother.left.color == BLACK)
			&& (brother.right == null || brother.right.color == BLACK)) {
		    // 如果parent此时为红，则把brother的黑色转移到parent上
		    if (parent.color == RED) {
			parent.color = BLACK;
			brother.color = RED;
			break;
		    } else {// 如果此时parent为黑，即此时全黑了，则把brother涂红，导致brother分支少一个黑，使整个分支都少了一个黑，需要对parent又进行一轮调整
			brother.color = RED;
			replace = parent;
			parent = replace.parent;
		    }
		} else {
		    // case3 黑兄，兄弟的左孩子为红色，右孩子随意
		    if (brother.right != null && brother.right.color == RED) {
			brother.right.color = parent.color;
			parent.color = BLACK;
			leftRotate(brother);
			rightRotate(parent);
			// case4 黑兄，兄弟的右孩子为红色，左孩子随意
		    } else if (brother.left != null && brother.left.color == RED) {
			brother.color = parent.color;
			parent.color = BLACK;
			brother.left.color = BLACK;
			rightRotate(parent);
		    }

		    break;
		}
	    }
	}

	if (replace != null)
	    replace.color = BLACK;

    }

    public void delete(T key) {
	RBNode<T> node = searchNode(key);
	deleteNode(node);
    }

    public void test() {
	RBTree<Integer> t = new RBTree<>();
	t.insert(12);
	t.insert(1);
	t.insert(9);
	t.insert(2);
	t.insert(0);
	t.insert(11);
	t.insert(7);
	t.insert(19);
	t.insert(4);
	t.insert(15);
	t.insert(18);
	t.insert(5);
	t.insert(14);
	t.insert(13);
	t.insert(10);
	t.insert(16);
	t.insert(6);
	t.insert(3);
	t.insert(8);
	t.insert(17);

	t.display();
	System.out.println();
	System.out.println();

	t.delete(12);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(1);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(9);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(2);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(0);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(11);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(7);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(19);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(4);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(15);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(18);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(5);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(14);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(13);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(10);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(16);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(6);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(3);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(8);
	t.display();
	System.out.println();
	System.out.println();

	t.delete(17);
	t.display();
	System.out.println();
	System.out.println();

	t.display();
    }

}
