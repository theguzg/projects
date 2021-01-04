import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { LiverPageComponent } from './liver-page.component';

describe('LiverPageComponent', () => {
  let component: LiverPageComponent;
  let fixture: ComponentFixture<LiverPageComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ LiverPageComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(LiverPageComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
