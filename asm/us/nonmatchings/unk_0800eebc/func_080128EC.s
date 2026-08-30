.syntax unified
	.align 2, 0
	.global func_080128EC
	.thumb
	.thumb_func
	.type func_080128EC, %function
func_080128EC: @ 080128EC
	ldr r0, _08012900 @ =0x02034928
	ldr r0, [r0, #0x00]
	ldrh r1, [r0, #0x34]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	bne _08012904
	movs r0, #0x00
	b _08012906
	.byte 0x00, 0x00
_08012900: .4byte 0x02034928
_08012904:
	movs r0, #0x01
_08012906:
	bx lr
.syntax divided
