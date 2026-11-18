
# minigit

Git, rebuilt from scratch in C++.

No libgit2. No shortcuts. Just C++17, a hash function, and the idea that everything in Git is a file in a folder.

## Why

I use Git every day, so I wanted to know what actually happens when I type `git commit`. The best way to find out was to build it.

## Progress

* [X] `init`
* [ ] Object store: blobs, trees, commits
* [ ] `add`
* [ ] `commit`
* [ ] `log`

## How it works

Git is a content addressable store. Every file, folder, and commit is saved under the SHA1 hash of its content.

```
.git/
  HEAD              points to the current branch
  objects/          every blob, tree, and commit lives here
  refs/heads/       each branch points to a commit hash
```

The goal is to match real Git's object format byte for byte, so a hash from minigit equals the hash from real Git for the same data.

## Build and run

```
g++ -std=c++17 -Wall -Wextra src/main.cpp -o minigit
mkdir testrepo
cd testrepo
..\minigit.exe init
```

## Future improvements

* status, diff
* Branches and checkout
* Merge
* Binary index format
* Packfiles
* Remotes

## Stack

* C++17
* zlib and OpenSSL, planned for compression and hashing
