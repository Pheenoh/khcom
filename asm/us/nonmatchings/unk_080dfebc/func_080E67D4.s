.syntax unified
	.align 2, 0
	.global func_080E67D4
	.thumb
	.thumb_func
	.type func_080E67D4, %function
func_080E67D4: @ 080E67D4
	push {lr}
	cmp r0, #0x00
	bge _080E67DE
	ldr r2, _080E67FC @ =0x00001FFF
	adds r0, r0, r2
_080E67DE:
	lsls r0, r0, #0x03
	lsrs r0, r0, #0x10
	cmp r1, #0x00
	bge _080E67EA
	ldr r2, _080E6800 @ =0x00000FFF
	adds r1, r1, r2
_080E67EA:
	lsls r1, r1, #0x04
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	asrs r1, r1, #0x10
	bl func_080E548C
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080E67FC: .4byte 0x00001FFF
_080E6800: .4byte 0x00000FFF
.syntax divided
