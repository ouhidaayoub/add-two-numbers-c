# My Add Two Numbers Journey (C Language)

## What’s This All About?

This is the classic LeetCode problem: Add Two Numbers. You’re given two linked lists, each digit is in reverse order, and you need to return a new list that represents their sum — also in reverse.

Sounds easy, right? Well... here's what actually went down. 😅

---

## How I Started

I didn’t want to copy anything. I wanted to figure it out on my own. I knew I needed to:

- Loop through both lists
- Sum the digits
- Keep track of carry
- Build the result list step by step

So I made three pointers:

- `temp1` → walks through l1
- `temp2` → walks through l2
- `temp3` → builds the answer

And I also thought I needed two flags to tell me when l1 or l2 are done: `isThel1Ended`, `isThel2Ended`.

---

## What Went Wrong (And What I Learned)

### 1. The Flags Didn’t Protect Me

I thought using flags like this would stop me from touching a null pointer:

```c
if (temp1 == NULL) isThel1Ended = true;
```

Then later:

```c
if (!isThel1Ended) use temp1->val;
```

But the crash happened before the flag was even checked — because I was touching `temp1->val` **before** the flag was updated. Boom 💥

> **Lesson:** Flags are not shields. If the pointer is NULL, you check it *now*, not after.

---

### 2. I Flipped the Logic

I had this line:

```c
if (isThel1Ended && !isThel2Ended)
    temp3->val = temp1->val;  // 😐
```

Wait... if list 1 is DONE, why am I using its value?! I meant to use temp2's value.

> **Lesson:** If one list is over, use the other one’s value — don’t touch the ended one.

---

### 3. I Was Always Allocating the Next Node

Every loop, I did:

```c
temp3->next = createNewNode();
```

Even if I didn’t need it. So at the end, I had to `free()` the last one if there was no carry.

> **Lesson:** Don’t create what you might not use. It just adds clean-up headache.

---

## How It Ended

I finally:

- Removed the dangerous logic
- Used direct pointer checks: `if (temp1)` instead of flags
- Kept my logic structure but cleaned it up
- Passed 1569/1569 test cases

**Runtime:** 3ms  
**Memory:** 12.62MB  
**Accepted:** July 18, 2025

---

## If You're Reading This

I didn’t write the best code right away. I failed, I crashed, I cursed at my screen. But I kept fixing one thing at a time.

If you're struggling with pointers, linked lists, or even just feeling lost — you're not dumb. It just takes time. One bug at a time.

Stay sharp. Debug hard.

— OUHDIA Ayoub 👊