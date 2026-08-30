.syntax unified
	.align 2, 0
	.global func_080E7D64
	.thumb
	.thumb_func
	.type func_080E7D64, %function
func_080E7D64: @ 080E7D64
	push {lr}
	lsls r1, r1, #0x18
	ldr r2, _080E7D7C @ =0x09EF6A50
	lsrs r1, r1, #0x16
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	bl _0811D5B4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
_080E7D7C: .4byte 0x09EF6A50
.syntax divided
