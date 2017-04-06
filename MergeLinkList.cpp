DuLinkList Merge(DuLinkList head1, DuLinkList head2)
{
    DuLinkList p1 = head1;
    DuLinkList p2 = head2;
    DuLinkList pt;
    DuLinkList ret;
    if(p1->data <= p2->data)
    {
        pt = p1;
        p1 = p1->next;
    }
    else
    {
        pt = p2;
        p2 = p2->next;
    }
    ret = pt;
    while(p1 && p2)
    {
        if(p1->data <= p2->data)
        {
            pt->next = p1;
            pt = p1;
            p1 = p1->next;
        }
        else
        {
            pt->next = p2;
            pt = p2;
            p2 = p2->next;
        }
    }
    if(!p1)
    {
        pt->next = p2;
    }
    else
    {
        pt->next = p1;
    }
    return ret;
}
