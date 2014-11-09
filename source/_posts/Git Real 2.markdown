---
layout: post
title: "Git Real(2)"
date: 2014-11-09 12:18
comments: true
tags: 
	- git

---
![0]()
#**Level 1:INTERACTIVE REBASE**#
###**1. REBASE RECAP**###
> So you've been working on your feature branch for a couple days and you realize you need to bring commits back in from master. Now you could just merge in the branch but that would create an ugly merge commit. Use rebase to bring those changes into your branch without the merge commit.

```
git rebase master
```
<!--more-->
###**2. INTERACTIVE REBASE**###
> You're getting ready to merge in your feature branch, but first you want to clean up your commits a bit. Go ahead and use interactive rebase to edit your last 4 commits.

```
git rebase -i HEAD~4  /*alter commits in the same branch*/
```
We want to re-order these four commits.


###**3. COMMIT ORDERING**###
> You notice a critical error on your part. The commit where you wrote tests comes after the commit where you made the actual changes. Let's swap these 2 commits so that it looks like you wrote the tests first. Swap the 'Add tests' commit so that it comes before the 'Implement poodles' commit.

`editor:`
```
pick b3f1649 Add unicorn
pick f239187 Implement poodles  //change to pick 4b65a5a Add tests 
pick 4b65a5a Add tests          //change to pick f239187 Implement poodles
pick c3f863f Added a title to the homepage
```
Swap the order,save and close the editor.Commits get replayed in new order.

###**4. REWORDING A COMMIT**###
> 1.As you're editing your commits, you notice that the commit that says 'Add tests' is a little vague, maybe you should change it to something more specific. Use the reword command to change the message of this commit.

`editor:`
```
pick b3f1649 Add unicorn
pick 4b65a5a Add tests // reword 4b65a5a Add tests
pick f239187 Implement poodles
pick c3f863f Added a title to the homepage
```
Commands:
p, pick = use commit
r, reword = use commit, but edit the commit message
e, edit = use commit, but stop for amending
s, squash = use commit, but meld into previous commit
f, fixup = like "squash", but discard this commit's log message
x, exec = run command (the rest of the line) using shell

> 2.After setting the `reword` command in the interactive rebase editor **another editor window has opened up**. This is where you actually change the commit message. Go ahead and change the commit message to: `Add tests for poodles` to be more descriptive.

`editor:`
```
Add tests //Add tests for poodles
```
###**3. SPLIT COMMITS**###
> 1.You remember that the 'Add unicorn' commit also contains the testing changes. Since we have separate commits for adding tests for poodles it makes sense to split out the test changes into a separate commit. Tell git to stop at this commit so we can reorganize it a bit.

`editor:`
```
pick b3f1649 Add unicorn   //edit b3f1649 Add unicorn
pick 4b65a5a Added tests for poodles
pick f239187 Implement poodles
pick c3f863f Added a title to the homepage
```
> 2.After saving the interactive rebase text file, git has stopped at the 'Add unicorn' commit. The first thing we need to do is to reset back to the previous commit, so the changes in the most recent commit are back in the file and unstaged.

```
git reset HEAD^ 
```

> 3.Great! You've already re-committed the changes needed in 2 different commits. All that's left to do is to resume the rebase with the continue option.

```
git rebase --continue
```
One commit is now two.

###**4. SQUASHING COMMITS**###
> 1.You noticed another bug with those pesky poodles, so you've gone ahead and fixed it, making another commit in the process. Now you have 2 commits that both affect the poodles page. You should squash them into one commit to simplify your git logs.

`editor:`
```
pick b3f1649 Add unicorn
pick 4b65a5a Add tests
pick f239187 Implement poodles
pick c3f863f Add title to poodle page //squash c3f863f Add title to poodle page
```

> 2.After designating a commit to be squashed, another editor pops up enabling you to set a commit message for the resulting commit. Go ahead and set to: `squashed some poodles`.

`editor:`
```
# This is a combination of 2 commits.
# The first commit's message is:

Implement poodles //注释掉

# This is the 2nd commit message:

Add title to poodle page //注释掉

#合并成你想的名字：
squashed some poodles
```
The content of two commits is replayed, but only one commit is made.
<br>
#**Level 2: STASHING**#
###**1. GIT STASH**###
> You're not quite ready to commit what you're working on, but need to make a quick fix to master. Fear not, just stash your current changes so you can switch to master quick.

```
git stash save  // = git stash
```

###**2. GIT STASH LIST**###
> You just finished making those quick changes to master. You're now ready to resume your work on the feature you had started on before you had to fix master. Let's first list all the stashes to make sure we get the right one.

```
git stash list   //stash names are shown in the list 
```

###**3. GIT STASH APPLY**###
> Great! As you can see, your stash is in the stash list. Let's apply the stash so you can get back to work.

```
git stash apply stash@{0} // = git stash apply
```
`stash@{0}` is the default.
stash has been applied but it's still here.
###**4. GIT STASH DROP**###
> Ok, so now that you have all your stashed changes back, let's clean up the stash list. There's only one stash; go ahead and drop it.

```
git stash drop  //Delete stash@{0} from list
git stash clear //Clear all of them at once
```
###**5. CONFLICTS**###
> 1.You came back from master and resumed working on your feature, when you realize that you forgot to apply your saved stash. Go ahead and apply it now.

```
git stash apply
```

> 2.Uh oh! There was a conflict when trying to apply your previous stash. It's no problem, you were just trying things anyway. Go ahead and do a hard reset back to the last commit.

```
git reset --hard HEAD
git stash apply
```

###**6. GIT STASH POP**###
> Now that you have the file reset, use the `pop` command to **apply and delete the stash at the same time**. 

```
git stash pop 
```

###**7. KEEPING THE INDEX**###
> You need to swap branches again, but this time some of your changes are ready to be committed. Stash all the unstaged changes, but leave the staged changes intact so they can be committed afterwards.

```
git stash save --keep-index //cause the staging area not to be stashed
```

###**8. INCLUDE UNTRACKED**###
> Wow, there are so many small fixes on master today! You really need to stash some more changes, but it doesn't seem to be working on these untracked files you just created. Try using the `--include-untracked` option to stash all those new files.

```
git stash save --include-untracked //cause untracked files to be stashed,too
```

###**9. LIST OPTIONS**###
> You've been stashing stuff all day since you keep having to make small quick fixes to master. Now you have a bunch of stashed changes and you're not sure which one you need to apply. You could look through them all one by one, or you could use the `--stat` option to list information about each stash. Give that a try.
```
git stash list --stat //summarizes file changes
```
###**10. STASH DETAILS**###
> You now have a list of stashes that are showing you more information, and you think you may have spotted the stash that you need. Take a more detailed look at the stash@{2} stash with the `--patch` option.

```
git stash show stash@{2} --patch //show file differents
```
###**11. STASH MESSAGE**###
> You're halfway through a large feature. Your team has decided that they want you to deploy what you have so far, but you have a smaller unfinished feature that isn't ready to be committed yet. Go ahead and stash your current changes with the **message `Added groom method`**, so you know which stash has your changes.

```
git stash save "Added groom method" 
```
###**12. STASH BRANCHING**###
> Now that you've deployed the main part of your feature, you need to finish up what is left. Create a new branch named `poodle` and apply your most current stash all in one command.

```
git stash branch poodle stash@{0}
```
`git stash branch`checks a new branch out automatically, and drops the stash automatically.

#**Level 3: PURGING HISTORY**#
![17]()
###**1. REPO COPY**###
> Now you've done it. You accidentally put the company's master password into one of your files. You're beginning to panic because you know that it's pretty hard to delete something forever in git. That's what you really need to do, though, or you're in big trouble. You're going to need to purge the history. First, though, make a copy of your repo in case you mess it up. Make a copy of the `poodles` repository, and name it whatever you want.

```
git clone poodles poodles_copy
```

###**2. TREE FILTER**###
> Luckily for you, the password you accidentally committed was in the `master_password.txt` file. Use the `filter-branch` command and remove this file from all of your commits.

```
//git filter-branch --tree-filter <command> ... 
//specify any shell commend
git filter-branch --tree-filter 'rm -f master_password.txt'
```
`...`: 
--all option filter all commits in all branches.
HEAD filter only current branch.

Git will check each commit out into **working directory**, run your command, and re-commit.

###**3. INDEX FILTER**###
> This repository is so large, using `--tree-filter` is going to take all day. Use `--index-filter` to remove `master_password.txt` instead. Remember, `--index-filte`r will need a command that works on the staging area, which is going to be some sort of git command.

```
//git filter-branch --index-filter <command> ...
//command must operate on staging area.
git filter-branch --index-filter 'git rm --cached --ignore-unmatch master_password.txt'
```
It operates on **staging area**. 
`--ignore-unmatch`: succeeds even if file isn't present.
Git will run your command against each commit, but without checking it out first(so it's faster).
###**4. FORCE**###
> You just realized that you also have a `master_username.txt` file that should probably be removed too, just to be safe. Use either technique you have learned to remove this file. Don't forget, you have a history backup from the first time you used `filter-branch`. Use the correct option to force git to overwrite it.

After you run filter-branch, Git leaves a backup of your tree in the ".git" directory.By default, you can't run filter-branch again because it won't overwrite the backup.You can force it with the -f option.
```
git filter-branch -f --tree-filter 'git rm --cached --ignore-unmatch master_username.txt'
```

###**5. PRUNING**###
> Great! Now we're getting somewhere. There is one more problem though, you realize that some of the commits don't contain anything anymore, since you removed the password file that they referenced. You should probably use the `--prune-empty` option do something to clean these out.

```
git filter-branch -f --prune-empty
```
`--prune-empty` option drops commits that don't alter any files.

#**Level 4: WORKING TOGETHER**#

###**1. PRUNING**###
> 

```

```