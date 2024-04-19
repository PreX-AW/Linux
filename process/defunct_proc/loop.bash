while true; do
	ps axj | head -1 && ps axj | grep defunct_proc | grep -v grep
	sleep 1
done
