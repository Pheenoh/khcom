.syntax unified
	.align 2, 0
	.global func_080DF804
	.thumb
	.thumb_func
	.type func_080DF804, %function
func_080DF804: @ 080DF804
	lsls r0, r0, #0x18
	ldr r1, _080DF810 @ =0x09EF69FC
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bx lr
_080DF810: .4byte 0x09EF69FC
.syntax divided
