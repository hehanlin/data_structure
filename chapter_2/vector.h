typedef int Rank;
#define DEFAULT_CAPACITY 3 //默认容量

template <typename T> class Vector{
    protected:
        Rank _size; //当前元素数量
        int _capacity; //容量
        T* _elem;   //元素

        //复制其他区间A[lo,hi)
        void copyFrom(T* const A, Rank lo, Rank hi) {
            _elem = new T[_capacity = 2*(hi-lo)];
            _size = 0;
            while(lo<hi) {
                _elem[_size++] = A[lo++];
            }
        }

        //扩容
        void expand() {
            if(_size<_capacity) return; //不满员不必扩容
            _capacity = max(_capacity, DEFAULT_CAPACITY);   //不低于最小容量
            T* oldElem = _elem; _elem = new T[_capacity<<=1]; //容量加倍
            for(int i = 0; i<_size; i++) {
                _elem[i] = oldElem[i];
            }
            delete [] oldElem;
        }

        //缩容
        void shrink() {
            if(_capacity < DEFAULT_CAPACITY<<1) return; //保证不收缩到DEFAULT_CAPACITY以下
            if(_size<<2 > _capacity) return;    //低于25%再收缩
            T* oldElem = _elem; _elem = new T[_capacity>>=1]; //容量减半
            for(int i = 0; i < _size; i++) {
                _elem[i] = oldElem[i];
            }
            delete [] oldElem;
        }

        //重载下标操作符
        operator[] (Rank r) const {
            return _elem[r];
        }   //assert: 0<=r<_size

        bool bubble ( Rank lo, Rank hi ); //扫描交换
        void bubbleSort ( Rank lo, Rank hi ); //起泡排序算法
        Rank max ( Rank lo, Rank hi ); //选取最大元素
        void selectionSort ( Rank lo, Rank hi ); //选择排序算法
        void merge ( Rank lo, Rank mi, Rank hi ); //归并算法
        void mergeSort ( Rank lo, Rank hi ); //归并排序算法
        Rank partition ( Rank lo, Rank hi ); //轴点构造算法
        void quickSort ( Rank lo, Rank hi ); //快速排序算法
        void heapSort ( Rank lo, Rank hi ); //堆排序（稍后结合完全堆讲解）
}