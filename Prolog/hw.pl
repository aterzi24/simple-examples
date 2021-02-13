cost([], 0).
cost([active_unit(Name,Star)|Rem], Cost) :- cost(Rem, OldCost), unit(Name, BaseCost, _), pow(3, Star-1, Coeff), Cost is BaseCost * Coeff + OldCost.


sort_units(X,Y) :- sort_helper(X, [], Y).

sort_helper([], Y, Y).
sort_helper([H|Rem], Res, Y) :- ss(H, Rem, NewList, Min), sort_helper(NewList, [Min|Res], Y).

ss(H, [], [], H).
ss(H, [X|Xs], [H|NewList], Min) :- unit(H, L1, _), unit(X, L2, _), L1 >= L2, ss(X, Xs, NewList, Min).
ss(H, [X|Xs], [X|NewList], Min) :- unit(H, L1, _), unit(X, L2, _), L1 < L2, ss(H, Xs, NewList, Min).


buyable([Unit], Money, [Unit], NewM) :- unit(Unit, Cost, _), Cost =< Money, NewM is Money-Cost, !.
buyable([Unit|Rem], Money, [Unit|Bought], RemMoney) :- unit(Unit, Cost, _), Cost =< Money, NewM is Money-Cost, buyable_helper(Rem, NewM, Bought, RemMoney).
buyable([_|Rem], Money, Bought, RemMoney) :- buyable(Rem, Money, Bought, RemMoney).

buyable_helper([], Money, [], Money).
buyable_helper([_|Rem], Money, Bought, RemMoney) :- buyable_helper(Rem, Money, Bought, RemMoney).
buyable_helper([Unit|Rem], Money, [Unit|Bought], RemMoney) :- unit(Unit, Cost, _), Cost =< Money, NewM is Money-Cost, buyable_helper(Rem, NewM, Bought, RemMoney).
