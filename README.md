Application to internet machines discovery and analysis


	/daemon: Daemon to discovery, fingerprint and portscan
	db.txt: DataBase scheme




*daemon:

	*features:
		*	IPV4
		*	Adquisition IPV4 random IP and file list input
		*	Multithread
		*	Multiprocess
		* 	Port scan tcp connect and tcp syn
		* 	Scan and connect over VPN
		* 	Multiport scan and figer
		* 	Multiservice (SSH)
		*	Geo IP location
		*	Savee data into MySQL database
		*	Comunication with agent
		*	Configuration file 
		*	Save scan state with resume possiblity
		*	Max thread 75, Max process 10 
	
	*roadmap:
		*	Multi network interfaces
		*	Multi agents output
		*	Multi threads tcp syn scan
		*	PF or BPF socket (case in study)
		*	Port scan UDP
		*	UDP protocols (no disclosured all)
		*	Scan and connect over TOR
		*	IPV6 (not disclosured) 
		*	Geo IP location city and ISP infomation
		*	Adquisition IPV6 (not disclosured)
		*	Adquisition method MySQL and socket
		*	Most tcp scan methods
		*	Most service finger methods (not disclosured all)
		*	Automatic protocol detection (not disclosured)
		*	Connection over jennyproxy

