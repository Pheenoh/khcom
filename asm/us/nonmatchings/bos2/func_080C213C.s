.syntax unified
	.align 2, 0
	.global func_080C213C
	.thumb
	.thumb_func
	.type func_080C213C, %function
func_080C213C: @ 080C213C
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r1, r4, #0x04
	ldr r0, _080C2174 @ =0x09EF2AA4
	adds r1, r1, r0
	movs r0, #0x01
	movs r2, #0x02
	movs r3, #0x02
	bl func_0800516C
	ldr r0, _080C2178 @ =0x09EF2D94
	lsls r4, r4, #0x02
	adds r4, r4, r0
	ldr r1, [r4, #0x00]
	lsls r5, r5, #0x15
	lsrs r5, r5, #0x10
	movs r0, #0x01
	adds r2, r5, #0x0
	bl LoadBgTiles
	pop {r4, r5}
	pop {r0}
	bx r0
_080C2174: .4byte 0x09EF2AA4
_080C2178: .4byte 0x09EF2D94
.syntax divided
