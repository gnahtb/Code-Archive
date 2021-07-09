const fi='';
      fo='';
      lim=100000;
var rslt,b1,q,l,m:int64;
    a:array[0..lim+5] of longint;
    c:boolean;
procedure enter;
var i:longint;
begin
        assign(input,fi);
        reset(input);
        readln(b1,q,l,m);
        for i:=1 to m do read(a[i]);
        close(input);
end;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
        i:=l;
        j:=r;
        x:=a[(l+r) div 2];
        repeat
                while a[i]<x do inc(i);
                while x<a[j] do dec(j);
                if not(i>j) then
                        begin
                                y:=a[i];
                                a[i]:=a[j];
                                a[j]:=y;
                                inc(i);
                                dec(j);
                        end;
        until i>j;
        if l<j then sort(l,j);
        if i<r then sort(i,r);
end;
function search(x:longint):boolean;
var l,r,med:longint;
begin
        l:=1;
        r:=m;
        repeat
                med:=(l+r) div 2;
                if a[med]<x then l:=med+1;
                if a[med]>x then r:=med-1;
                if a[med]=x then exit(true);
        until l>r;
        exit(false);
end;
procedure solve;
var i:longint;
    t:int64;
begin
        c:=true;
        t:=b1*q;
        for i:=1 to 40 do
                if abs(t)<=l then
                        begin
                                if not search(t) then inc(rslt);
                                t:=t*q;
                        end
                else break;
end;
procedure print;
begin
        assign(output,fo);
        rewrite(output);
        if c then write(rslt)
        else write('inf');
        close(output);
end;
begin
        enter;
        sort(1,m);
        c:=false;
        rslt:=0;
        if abs(b1)>l then c:=true;
        if (abs(b1)<=l) and not search(b1) then inc(rslt);
        if (b1*q=0) and search(0) then c:=true;
        if (q=1) and search(b1) then c:=true;
        if (q=-1) and search(b1) and search(-b1) then c:=true;
        if (b1*q<>0) and (abs(q)<>1) then solve;
        print;
end.
