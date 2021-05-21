class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        res = []
        content_dict = dict()
        for path in paths:
            directory, *files = path.split(' ')
            for file in files:
                name = file[:file.find("(")]
                text = file[file.find("(") + 1:file.find(")")]
                if text not in content_dict:
                    content_dict[text] = []
                content_dict[text].append(directory + "/" + name)
        for key in content_dict:
            if len(content_dict[key]) > 1:
                res.append(content_dict[key])
        return res