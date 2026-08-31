.syntax unified
	.align 2, 0
	.global task_wlogo_atl_0
	.thumb
	.thumb_func
	.type task_wlogo_atl_0, %function
task_wlogo_atl_0: @ 080B525C
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r1, _080B52CC @ =0x096FAD84
	movs r0, #0x00
	movs r2, #0x20
	bl LoadBgPalette
	ldr r1, _080B52D0 @ =0x09633D64
	movs r2, #0x90
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgTiles
	ldr r1, _080B52D4 @ =0x096B8464
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgMap
	ldr r5, _080B52D8 @ =0x09634664
	movs r0, #0x00
	bl GetBgCharBase
	adds r1, r0, #0x0
	adds r1, #0x20
	movs r2, #0xD8
	lsls r2, r2, #0x02
	adds r0, r5, #0x0
	bl RequestDma3Copy
	movs r0, #0x00
	movs r1, #0x00
	strh r1, [r4, #0x02]
	strb r0, [r4, #0x00]
	strb r0, [r4, #0x08]
	strb r0, [r4, #0x04]
	strh r1, [r4, #0x06]
	movs r0, #0x04
	strb r0, [r4, #0x09]
	strh r1, [r4, #0x0A]
	movs r0, #0x00
	movs r1, #0x10
	movs r2, #0x00
	bl func_080057A0
	ldr r0, _080B52DC @ =0x080B5445
	bl func_080081B8
	ldrb r1, [r4, #0x09]
	movs r0, #0x00
	movs r2, #0x04
	bl func_080081E4
	pop {r4, r5}
	pop {r0}
	bx r0
_080B52CC: .4byte 0x096FAD84
_080B52D0: .4byte 0x09633D64
_080B52D4: .4byte 0x096B8464
_080B52D8: .4byte 0x09634664
_080B52DC: .4byte 0x080B5445
.syntax divided
