.syntax unified
	.align 2, 0
	.global func_080E0010
	.thumb
	.thumb_func
	.type func_080E0010, %function
func_080E0010: @ 080E0010
	adds r1, r0, #0x0
	ldr r0, _080E002C @ =0xFFFF8800
	adds r1, r1, r0
	ldr r0, _080E0030 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x10]
	lsls r0, r0, #0x0B
	ldr r2, _080E0034 @ =0xFFFF1000
	adds r0, r0, r2
	cmp r1, #0x00
	bge _080E0038
	movs r1, #0x00
	b _080E003E
	.byte 0x00, 0x00
_080E002C: .4byte 0xFFFF8800
_080E0030: .4byte 0x02039BA0
_080E0034: .4byte 0xFFFF1000
_080E0038:
	cmp r1, r0
	ble _080E003E
	adds r1, r0, #0x0
_080E003E:
	adds r0, r1, #0x0
	bx lr
	.byte 0x00, 0x00
.syntax divided
