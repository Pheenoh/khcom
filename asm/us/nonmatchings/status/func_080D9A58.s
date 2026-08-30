.syntax unified
	.align 2, 0
	.global func_080D9A58
	.thumb
	.thumb_func
	.type func_080D9A58, %function
func_080D9A58: @ 080D9A58
	push {lr}
	bl func_080D9A14
	ldr r0, _080D9A84 @ =0x0203C568
	movs r1, #0x00
	strb r1, [r0, #0x00]
	ldr r1, _080D9A88 @ =0x0203C560
	ldrh r0, [r1, #0x00]
	cmp r0, #0x02
	bhi _080D9A7E
	movs r0, #0x03
	strh r0, [r1, #0x00]
	ldr r1, _080D9A8C @ =0x0203C554
	movs r2, #0x87
	lsls r2, r2, #0x02
	adds r0, r2, #0x0
	ldrh r2, [r1, #0x00]
	adds r0, r0, r2
	strh r0, [r1, #0x00]
_080D9A7E:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D9A84: .4byte 0x0203C568
_080D9A88: .4byte 0x0203C560
_080D9A8C: .4byte 0x0203C554
.syntax divided
