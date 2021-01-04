import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { LiverComponent } from './liver.component';

describe('LiverComponent', () => {
  let component: LiverComponent;
  let fixture: ComponentFixture<LiverComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ LiverComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(LiverComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
