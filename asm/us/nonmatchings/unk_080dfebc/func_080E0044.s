.syntax unified
	.align 2, 0
	.global func_080E0044
	.thumb
	.thumb_func
	.type func_080E0044, %function
func_080E0044: @ 080E0044
	adds r1, r0, #0x0
	ldr r0, _080E0060 @ =0xFFFFA000
	adds r1, r1, r0
	ldr r0, _080E0064 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x12]
	lsls r0, r0, #0x0B
	ldr r2, _080E0068 @ =0xFFFF6000
	adds r0, r0, r2
	cmp r1, #0x00
	bge _080E006C
	movs r1, #0x00
	b _080E0072
	.byte 0x00, 0x00
_080E0060: .4byte 0xFFFFA000
_080E0064: .4byte 0x02039BA0
_080E0068: .4byte 0xFFFF6000
_080E006C:
	cmp r1, r0
	ble _080E0072
	adds r1, r0, #0x0
_080E0072:
	adds r0, r1, #0x0
	bx lr
	.byte 0x00, 0x00
.syntax divided
