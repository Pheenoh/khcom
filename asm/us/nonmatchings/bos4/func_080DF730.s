.syntax unified
	.align 2, 0
	.global func_080DF730
	.thumb
	.thumb_func
	.type func_080DF730, %function
func_080DF730: @ 080DF730
	push {r4, lr}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r4, _080DF74C @ =0x0203C590
	strb r0, [r4, #0x06]
	adds r0, r1, #0x0
	bl func_080DEBAC
	strb r0, [r4, #0x07]
	bl _080DEC44
	pop {r4}
	pop {r0}
	bx r0
_080DF74C: .4byte 0x0203C590
.syntax divided
