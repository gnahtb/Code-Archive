const fi='';
      fo='';
      lim=100000;
type tarray=array[0..lim+5] of int64;
var a,b,p:tarray;
    n,s:int64;
    ans:string;
procedure enter;
var i:longint;
begin
        assign(input,fi);
        reset(input);
        readln(n);
        s:=0;
        for i:=1 to n do
                begin
                        read(a[i]);
                        b[i]:=a[i];
                        p[i]:=i;
                        s:=s+int64(a[i]);
                end;
        close(input);
end;
procedure swap(var x,y:int64);
var t:int64;
begin
        t:=x;
        x:=y;
        y:=t;
end;
function check:boolean;
var i:longint;
    t:int64;
begin
        t:=0;
        for i:=1 to n do
                begin
                        t:=t+int64(a[i]);
                        if t*2=s then
                                begin
                                        ans:='YES';
                                        exit(true);
                                end;
                end;
        exit(false);
end;
procedure sort(var c:tarray;l,r:longint);
var i,j:longint;
    x:int64;
begin
        i:=l;
        j:=r;
        x:=c[(l+r) div 2];
        repeat
                while c[i]<x do inc(i);
                while x<c[j] do dec(j);
                if i<=j then
                        begin
                                swap(b[i],b[j]);
                                swap(p[i],p[j]);
                                inc(i);
                                dec(j);
                        end;
        until i>j;
        if l<j then sort(c,l,j);
        if i<r then sort(c,i,r);
end;
procedure sortpos;
var i,j:longint;
begin
        i:=1;
        while i<=n do
                begin
                        j:=i;
                        while b[j+1]=b[i] do inc(j);
                        sort(p,i,j);
                        i:=j+1;
                end;
end;
function findmax(x:int64):longint;
var l,r,mid,q:longint;
begin
        q:=0;
        l:=1;
        r:=n;
        while l<=r do
                begin
                        mid:=(l+r) div 2;
                        if b[mid]<=x then
                                begin
                                        if b[mid]=x then q:=mid;
                                        l:=mid+1;
                                end
                        else r:=mid-1;
                end;
        exit(q);
end;
function findmin(x:int64):longint;
var l,r,mid,q:longint;
begin
        q:=0;
        l:=1;
        r:=n;
        while l<=r do
                begin
                        mid:=(l+r) div 2;
                        if b[mid]>=x then
                                begin
                                        if b[mid]=x then q:=mid;
                                        r:=mid-1;
                                end
                        else l:=mid+1;
                end;
        exit(q);
end;
procedure solve;
var i,q:longint;
    x,t:int64;
begin
        t:=0;
        for i:=1 to n do
                begin
                        t:=t+int64(a[i]);
                        x:=s-t*2;
                        if not odd(x) then
                                if x<0 then
                                        begin
                                                q:=findmin(abs(x) div 2);
                                                if (q>0) and (p[q]<=i) then
                                                        begin
                                                                ans:='YES';
                                                                exit;
                                                        end;
                                        end
                                else
                                        begin
                                                q:=findmax(abs(x) div 2);
                                                if (q>0) and (p[q]>i) then
                                                        begin
                                                                ans:='YES';
                                                                exit;
                                                        end;
                                        end;
                end;
end;
procedure print;
begin
        assign(output,fo);
        rewrite(output);
        write(ans);
        close(output);
end;
begin
        fillchar(a,sizeof(a),0);
        fillchar(b,sizeof(b),0);
        fillchar(p,sizeof(p),0);
        ans:='NO';
        enter;
        if not odd(s) then
                if not check then
                        begin
                                sort(b,1,n);
                                sortpos;
                                solve;
                        end
                else ans:='YES';
        print;
end.
