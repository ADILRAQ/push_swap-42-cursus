# push_swap-42-cursus
<p>This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions.</p>

# Rules

<p>You have 2 stacks named a and b.</p>
<ul>
    At the beginning:
        <li>◦ The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.</li>
        <li>◦ The stack b is empty.</li>
</ul>

# Instructions

<p>• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:</p>
<ul>
    <li>sa (swap a): Swap the first 2 elements at the top of stack a.
    Do nothing if there is only one or no elements.</li>
    <li>sb (swap b): Swap the first 2 elements at the top of stack b.
    Do nothing if there is only one or no elements.</li>
    <li>ss : sa and sb at the same time.</li>
    <li>pa (push a): Take the first element at the top of b and put it at the top of a.
    Do nothing if b is empty.</li>
    <li>pb (push b): Take the first element at the top of a and put it at the top of b.
    Do nothing if a is empty.</li>
    <li>ra (rotate a): Shift up all elements of stack a by 1.
    The first element becomes the last one.</li>
    <li>rb (rotate b): Shift up all elements of stack b by 1.
    The first element becomes the last one.</li>
    <li>rr : ra and rb at the same time.</li>
    <li>rra (reverse rotate a): Shift down all elements of stack a by 1.
    The last element becomes the first one.</li>
    <li>rrb (reverse rotate b): Shift down all elements of stack b by 1.
    The last element becomes the first one.</li>
    <li>rrr : rra and rrb at the same time.</li>
</ul>