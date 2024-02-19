const app = Vue.createApp({
  'data': () => {
    return { 
      'userName': 'Carlos',
      'userAge': 40,
      'userImageUrl': 'https://upload.wikimedia.org/wikipedia/commons/b/bd/Test.svg'
    }
  },
  'methods': {
    getFavoriteNumber: () => {
      return Math.random();
    }
  }
});

app.mount('#assignment');