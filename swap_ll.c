struct node* swapNodes(struct node *head, int x, int y) {
    if (x == y) return head;

    struct node *currentX = *head, *prevX = NULL;
    while (currentX != NULL &&  currentX->data != x) {
        prevX = currentX;
        currentX = currentX->next;
    }
    
    struct node *currentY = *head, *prevY = NULL;
    while (currentY != NULL && currentY->data != y) {
        prevY = currentY;
        currentY = currentY->next;
    }
    
    if (currentX == NULL || currentY == NULL) return head;
    
    if (prevX == NULL) {
        head = currentY;
    }
    else {
        prevX->next = currentY;
    }
    
    if (prevY == NULL) {
        head = currentX;
    }
    else {
        prevY->next = currentX;
    }
    
    Node *temp = currentY->next;
    currentY->next = currentX->next;
    currentX->next = temp;
    return head;
}
