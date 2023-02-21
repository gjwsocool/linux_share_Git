#import numpy as np
from random import sample
import rank.util.recall_service_client as recall_client
#import rank.dataset.feature as dataset



def anime_rank(context,n):
    recall_res=recall_client.get_recall(context.user_id)
    return sample(recall_res,n)
