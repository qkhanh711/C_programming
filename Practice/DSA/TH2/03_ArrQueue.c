#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10
typedef struct {
    int data[MAX_SIZE];
    int front; // vị trí đầu hàng đợi
    int rear; // vị trí cuối hàng đợi
    int size; // số lượng phần tử trong hàng đợi
} Queue;

void initQueue(Queue *q);
// Khởi tạo một hàng đợi rỗng.
bool isEmptyQueue(Queue *q);
// Trả về true nếu hàng đợi rỗng, false nếu không rỗng.
bool isFullQueue(Queue *q);
// Trả về true nếu hàng đợi đầy, false nếu không đầy.
void enqueue(Queue *q, int value);
// Thêm một phần tử có giá trị value vào cuối hàng đợi. Nếu hàng đợi đầy, in thông báo lỗi.
int dequeue(Queue *q);
// Lấy và xóa phần tử ở đầu hàng đợi. Giá trị trả về của hàm là giá trị của phần tử lấy ra. Nếu
// hàng đợi rỗng, in thông báo lỗi và trả về -1.
int peek(Queue *q);
// Trả về giá trị của phần tử ở đầu hàng đợi, không xóa phần tử đó. Nếu hàng đợi rỗng, in
// thông báo lỗi và trả về -1.

// 1) Khai báo các cấu trúc dữ liệu và các hàm đã cho.
// 2) Hoàn thiện các hàm thao tác trên hàng đợi sử dụng mảng tĩnh.
// 3) Hoàn thiện hàm initQueue():
void initQueue(Queue *q) {
    q->front = 0 ;
    q->rear = -1 ;
    q->size = 0 ;
}
// 4) Hoàn thiện hàm isEmptyQueue():
bool isEmptyQueue(Queue *q) {
    return q->size == 0 ;
}
// 5) Hoàn thiện hàm isFullQueue():
bool isFullQueue(Queue *q) {
    return q->size == MAX_SIZE ;
}
// 6) Hoàn thiện hàm enqueue():
void enqueue(Queue *q, int value) {
    if ( isFullQueue(q)) { // Kiểm tra hàng đợi đầy
    printf("Queue is full. Cannot enqueue %d\n", value);
    return;
    }
    q->rear = ( q->rear + 1) % MAX_SIZE ; // Tính vị trí rear mới (vòng tròn)
    q->data[q->rear] = value; // Gán giá trị vào vị trí rear
    q->size++ ; // Tăng kích thước
    }
// 7) Hoàn thiện hàm dequeue():
int dequeue(Queue *q) {
    if ( isEmptyQueue(q)) { // Kiểm tra hàng đợi rỗng
    printf("Queue is empty. Cannot dequeue.\n");
    return 0 ; // Giá trị trả về khi lỗi
    }
    int value = q->data[q->front]; // Lấy giá trị ở đầu hàng đợi
    q->front = ( q->front + 1) % MAX_SIZE ; // Cập nhật vị trí front (vòng tròn)
    q->size-- ; // Giảm kích thước
    return value;
}
// 8) Hoàn thiện hàm peek():
int peek(Queue *q) {
    if ( isEmptyQueue(q)) { // Kiểm tra hàng đợi rỗng
    printf("Queue is empty. Cannot peek.\n");
    return 0 ; // Giá trị trả về khi lỗi
    }
    return q->data[q->front]; // Trả về giá trị ở đầu hàng đợi
}
// 9) Viết đoạn mã trong hàm main() để:
// o Khởi tạo một hàng đợi q.
// o Thêm các phần tử 10, 20, 30 vào hàng đợi.
// o Xem giá trị phần tử đầu tiên (dùng peek).
// o Lấy ra 2 phần tử khỏi hàng đợi (dùng dequeue).
// o In ra các phần tử còn lại trong hàng đợi bằng cách lặp và dùng dequeue cho đến
// khi hàng đợi rỗng (tham khảo main() trong code gốc).

int main(){
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("o %d\n", peek(&q));
    printf("o Xem giá trị phần tử đầu tiên (dùng peek) %d\n", q.data[(q.front + 1) % MAX_SIZE]);
    printf("o Lấy ra 2 phần tử khỏi hàng đợi (dùng dequeue) %d\n", dequeue(&q));
    printf("o %d\n", dequeue(&q));
    printf("o In ra các phần tử còn lại trong hàng đợi bằng cách lặp và dùng dequeue cho đến khi hàng đợi rỗng\n");
    for (int i = 0; i < q.size; i++) {
        printf("\t+ %d\n", q.data[(q.front + i) % MAX_SIZE]);
    }
    return 0;
}

