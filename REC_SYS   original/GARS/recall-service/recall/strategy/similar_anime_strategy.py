from recall.strategy.recall_strategy import RecallStrategy
from recall.context import Context
import recall.dataset.anime as dataset
from typing import List


(anime_df,_)=dataset.load_dataset()
stored_df= anime_df.sort_index()

class SimilarAnimeStrategy(RecallStrategy):
    def name(self):
        return 'Similar Anime'
    
    def recall(self,context:Context,n=20) -> List[int]:
        anime_iloc=stored_df.index.get_loc(context.anime_id)

        from_index=anime_iloc
        if from_index+ n >len(stored_df):
            from_index=len(stored_df)-n

        return stored_df.iloc[from_index: from_index+n].index.to_list()