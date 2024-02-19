const app = Vue.createApp({
  'data': () => {
    return {
      'courseGoal': 'Finish the course and learn Vue!', // If you use HTML tags, won't be interpreted, to protect you from X-site scripting.
      'htmlContentTest': '<b>TEST HTML</b>',
      'vueLink': 'https://vuejs.org'
    };
  },
  'methods': {
    'outputGoal': () => {
      const randomNumber = Math.random();

      if (randomNumber < 0.5) {
        return 'Lean VUEEEEEEE';
      } else {
        return 'BE A VUE MASTER, MASTER'
      }
    }
  }
});

app.mount('#user-goal');