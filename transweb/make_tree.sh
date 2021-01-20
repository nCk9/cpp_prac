#!bash/bin
mkdir s1
mkdir s1/s3
touch s1/s3/conf.txt
echo "virtusl (conda) environments are my favourite new technology" > s1/s3/conf.txt
mkdir s1/s2
touch s1/s2/text_chunk1.txt
echo "virtual environments are good for..." > s1/s2/text_chunk1.txt
echo "I like them because..." >> s1/s2/text_chunk1.txt
mkdir s1/s2/Advanced
touch s1/s2/Advanced/text_chunk2.txt
cp s1/s2/text_chunk1.txt s1/s2/Advanced/text_chunk2.txt
echo "Do you want to build a snowman?" >> s1/s2/Advanced/text_chunk2.txt


