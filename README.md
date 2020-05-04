# Drone_Data
A Cloud disk for all the data needed for drone system



One thing to mention before:

This website is only used for simulation on how a whole drone system works. 



## Basic Knowledge on how to use GitHub:

If you are a Windows user, maybe life is a little harder. Linux/ Mac OS can directly start with Terminal, while Windows user may have to do some other settings on their cmd first.

### SSH-KEY

If you use git for the first time, you need to add your user information to your computer first. Then your computer will generate a key called SSH-KEY which helps github (website) to know who are you. 

I've found two good explanations on how to generate an ssh-key and connect it to github. Just pick one or search by yourself.

https://help.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh (English)

https://blog.csdn.net/u013778905/article/details/83501204 (Chinese)

### Login in terminal (command line)

```bash
ssh -T git@github.com
```

Type the code above, and enter your password, then it will show a line like:

```bash
Hi Roihn! You've successfully authenticated, but GitHub does not provide shell access.
```

which means you succeed.

### Clone

To download or upload the data, you need to have a local repository which is the same as the one on the website first. Then you can do all your revisions in local repository, and upload it to the website when you want. 

 ```bash
git clone git@github.com:Roihn/Drone_Data.git /Users/pengrun/Desktop/pengrun/DRONE
 ```

you need to follow the following grammar:

```bash
git clone "the repository you need to clone" "where you want to put your local repository"
```

For this project, you only need to **change the latter one**.

### Push

After you have cloned the repository, and done some revisions on your local repository, you can push what you have done to the website.

```bash
git add . #which adds all your changes to the website
git commit -m "XXXX" #XXXX is the place for you to write what you have done on this version of your work
git push origin master  #finally you push your work to the website
```

You only need to change "XXXX" every time, and the mark "" is needed. 

One example:

```bash
git add . 
git commit -m "Readme updated" 
git push origin master 
```



**One thing to mention is that: you need to first use `cd` command to go into your local repository, and then type the commands above.**



# Useful Tool

There are some softwares like "Github Desktop" which simplifies the process above. If you have troubles with those above, maybe you can turn to use those tools instead.