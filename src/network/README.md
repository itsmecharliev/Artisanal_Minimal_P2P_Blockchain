Block Payload Layout:
My idea here is that the layout is ordered from
Block Identity | Relevance to previous block | Content
in which I consider: "Block Identity" as creation of time and existence in blockchain, 
"Relevance to previous block" as previous hash, 
and Content as block data.

Choice of using atomic:
This is to deal with race conditions. Since we are just dealing with flags,
we will try to use atomic as much as possible for performance.
https://en.cppreference.com/cpp/atomic/atomic

