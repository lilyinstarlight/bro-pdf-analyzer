module PDF;

export {
	type Info: record {
		ver: string &optional;
		pages: count;
		js: bool;
	};
}
