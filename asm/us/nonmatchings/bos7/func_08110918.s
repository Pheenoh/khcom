.syntax unified
	.align 2, 0
	.global func_08110918
	.thumb
	.thumb_func
	.type func_08110918, %function
func_08110918: @ 08110918
	ldr r1, [r0, #0x04]
	movs r2, #0x01
	adds r0, r1, #0x0
	adds r0, #0xCC
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r0, #0x00
	ble _08110930
	movs r3, #0x02
	ldsh r0, [r1, r3]
	cmp r0, #0x06
	bne _08110932
_08110930:
	movs r2, #0x00
_08110932:
	adds r0, r2, #0x0
	bx lr
	.byte 0x00, 0x00
.syntax divided
