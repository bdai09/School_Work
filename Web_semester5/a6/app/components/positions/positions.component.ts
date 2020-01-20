import { Component, OnInit, OnDestroy } from '@angular/core';
import { PositionService } from '../../data/position.service';
import { Position } from '../../data/positions';
import { Router } from '@angular/router';

@Component({
  selector: 'app-positions',
  templateUrl: './positions.component.html',
  styleUrls: ['./positions.component.css']
})

export class PositionsComponent implements OnInit, OnDestroy {

  private positions: Position[];
  private getPositionsSub;
  private loadingError: boolean = false;

  constructor(private p: PositionService, private router: Router) { }

  ngOnInit() {
    this.getPositionsSub = this.p.getPositions()
      .subscribe(
        positions => this.positions = positions,
        function (e) { this.loadingError = true; }
      );
  }

  routePosition(id: string) {
    this.router.navigate(['/position/', id]);
  }

  ngOnDestroy() {
    if (this.getPositionsSub != 'undefined') {
      this.getPositionsSub.unsubscribe();
    }
  }
}