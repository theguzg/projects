import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { ChokingComponent } from './choking.component';

describe('ChokingComponent', () => {
  let component: ChokingComponent;
  let fixture: ComponentFixture<ChokingComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ ChokingComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(ChokingComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
