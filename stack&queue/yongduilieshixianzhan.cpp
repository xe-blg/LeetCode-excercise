#include <queue>
using namespace std;
//用两个队列
class MyStack {
public:
    queue<int> que1;
    queue<int> que2;

    MyStack() {}

    void push(int x) {
        que1.push(x);
    }

    int pop() {
        int size = que1.size();
        for(int i=0; i<size-1; i++){
            que2.push(que1.front());
            que1.pop();
        }
        int result = que1.front();
        que1.pop();
        swap(que1, que2);
        return result;
    }

    int top() {
        int size = que1.size();
        for(int i=0; i<size-1; i++){
            que2.push(que1.front());
            que1.pop();
        }
        int result = que1.front();
        que2.push(que1.front());
        que1.pop();
        swap(que1, que2);
        return result;
    }

    bool empty() {
        return que1.empty();
    }
};

//用一个队列
class MyStack {
public:
    queue<int> que;

    MyStack() {

    }

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int size = que.size();
        size--;
        while (size--) { // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
            que.push(que.front());
            que.pop();
        }
        int result = que.front(); // 此时弹出的元素顺序就是栈的顺序了
        que.pop();
        return result;
    }

    int top(){
        int size = que.size();
        size--;
        while (size--){
            // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
            que.push(que.front());
            que.pop();
        }
        int result = que.front(); // 此时获得的元素就是栈顶的元素了
        que.push(que.front());    // 将获取完的元素也重新添加到队列尾部，保证数据结构没有变化
        que.pop();
        return result;
    }

    bool empty() {
        return que.empty();
    }
};