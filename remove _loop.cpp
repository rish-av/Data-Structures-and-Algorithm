void removeTheLoop(Node *node)
{
    Node* tort=node;
    Node* hare = node;
    int flag = 0;
    if(!node || !node->next){ //handle trivial cases
        return;
    }
    while(tort && hare){
        tort = tort->next;
        hare = hare->next->next;
        if(tort == hare){
            flag=1;
            break;
        }
        if(!hare || !hare->next){ //if linear in loop
            break;
        }
    }
    if(!tort|| !hare){
        return;
    }
    if(flag==1){
        Node* temp = node;
        Node* last;
        while(1){
            last = tort;
            tort = tort->next;
            temp = temp->next;
            if(temp==tort){
                break;
            }
        }
        last->next = NULL;
    }
}