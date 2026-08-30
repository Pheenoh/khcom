.syntax unified
	.align 2, 0
	.global task_bos_pc_0
	.thumb
	.thumb_func
	.type task_bos_pc_0, %function
task_bos_pc_0: @ 0810A580
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x020
	adds r7, r0, #0x0
	str r1, [sp, #0x014]
	ldr r0, _0810A720 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x40
	ldr r1, _0810A724 @ =0x09EF9E0C
	ldr r2, _0810A728 @ =0x09A3DF0C
	bl func_08000E14
	movs r2, #0xB4
	lsls r2, r2, #0x02
	adds r1, r7, r2
	str r0, [r1, #0x00]
	movs r4, #0x00
	strh r4, [r7, #0x00]
	strh r4, [r7, #0x02]
	movs r0, #0x96
	lsls r0, r0, #0x02
	strh r0, [r7, #0x04]
	strh r4, [r7, #0x06]
	strh r4, [r7, #0x08]
	movs r3, #0x00
	strb r3, [r7, #0x18]
	movs r0, #0xA8
	lsls r0, r0, #0x09
	str r0, [r7, #0x1C]
	movs r0, #0xB8
	lsls r0, r0, #0x09
	str r0, [r7, #0x20]
	movs r0, #0xAA
	lsls r0, r0, #0x09
	str r0, [r7, #0x24]
	ldr r0, _0810A72C @ =0xFFFFF800
	str r0, [r7, #0x28]
	str r4, [r7, #0x2C]
	strh r4, [r7, #0x30]
	strh r4, [r7, #0x34]
	movs r1, #0xBA
	lsls r1, r1, #0x02
	adds r0, r7, r1
	strh r4, [r0, #0x00]
	adds r2, #0x1A
	adds r0, r7, r2
	strb r3, [r0, #0x00]
	ldr r3, _0810A730 @ =0x000002EB
	adds r0, r7, r3
	movs r1, #0x00
	strb r1, [r0, #0x00]
	adds r2, #0x02
	adds r2, r7, r2
	str r2, [sp, #0x018]
	strb r1, [r2, #0x00]
	adds r3, #0x05
	adds r0, r7, r3
	str r4, [r0, #0x00]
	movs r0, #0xBD
	lsls r0, r0, #0x02
	adds r0, r7, r0
	str r0, [sp, #0x01C]
	str r4, [r0, #0x00]
	strh r4, [r7, #0x0A]
	ldr r0, _0810A734 @ =0x0000FFFF
	strh r0, [r7, #0x0C]
	adds r0, r7, #0x0
	movs r1, #0x00
	bl func_08109EF8
	adds r0, r7, #0x0
	bl func_08109F20
	adds r0, r7, #0x0
	bl func_0810A444
	adds r0, r7, #0x0
	bl func_0810A454
	movs r1, #0x54
	adds r1, r1, r7
	mov r10, r1
	ldr r2, _0810A738 @ =0x09A3DEFC
	mov r9, r2
	ldr r2, [r7, #0x20]
	ldr r3, [r7, #0x24]
	ldr r0, [r7, #0x28]
	str r0, [sp, #0x000]
	mov r0, r10
	mov r1, r9
	bl func_0801B37C
	movs r3, #0x88
	adds r3, r3, r7
	mov r8, r3
	ldr r2, [r3, #0x00]
	ldr r3, [r3, #0x04]
	ldr r0, _0810A73C @ =0x00000400
	ldr r1, _0810A740 @ =0x00000000
	orrs r2, r0
	movs r5, #0x04
	movs r6, #0x00
	adds r0, r2, #0x0
	orrs r0, r5
	adds r1, r3, #0x0
	mov r2, r8
	str r0, [r2, #0x00]
	str r1, [r2, #0x04]
	movs r3, #0xB2
	lsls r3, r3, #0x01
	adds r3, r3, r7
	mov r8, r3
	ldr r2, [r7, #0x20]
	ldr r3, [r7, #0x24]
	ldr r0, [r7, #0x28]
	ldr r1, _0810A744 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #0x000]
	mov r0, r8
	mov r1, r9
	bl func_0801B37C
	movs r3, #0xCC
	lsls r3, r3, #0x01
	adds r2, r7, r3
	ldr r0, [r2, #0x00]
	ldr r1, [r2, #0x04]
	orrs r0, r5
	str r0, [r2, #0x00]
	str r1, [r2, #0x04]
	mov r0, r8
	mov r1, r10
	bl func_0801BDD4
	movs r1, #0x9D
	lsls r1, r1, #0x02
	adds r0, r7, r1
	movs r1, #0x08
	movs r2, #0x20
	movs r3, #0x38
	bl func_080122AC
	ldr r1, _0810A748 @ =0x09D34A74
	movs r2, #0x80
	lsls r2, r2, #0x05
	movs r0, #0x01
	bl func_0800510C
	ldr r0, _0810A74C @ =0x09CB84B4
	movs r1, #0xAA
	lsls r1, r1, #0x04
	bl func_080026A4
	str r0, [r7, #0x40]
	movs r5, #0x80
	lsls r5, r5, #0x03
	ldr r6, _0810A750 @ =0x09C448D2
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl func_080028F8
	str r0, [r7, #0x44]
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl func_080028F8
	str r0, [r7, #0x48]
	ldr r0, _0810A754 @ =0x09D693D4
	movs r1, #0x60
	bl func_08002A14
	str r0, [r7, #0x4C]
	ldr r0, _0810A758 @ =0x08F69BC4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r7, #0x50]
	movs r0, #0x00
	movs r1, #0x01
	bl func_0801C298
	movs r2, #0xB5
	lsls r2, r2, #0x02
	adds r0, r7, r2
	str r4, [r0, #0x00]
	movs r3, #0xB6
	lsls r3, r3, #0x02
	adds r0, r7, r3
	str r4, [r0, #0x00]
	movs r1, #0xB7
	lsls r1, r1, #0x02
	adds r0, r7, r1
	str r4, [r0, #0x00]
	adds r2, #0x0C
	adds r0, r7, r2
	str r4, [r0, #0x00]
	movs r6, #0x00
	ldr r3, [sp, #0x014]
	cmp r3, #0x00
	bne _0810A75C
	adds r1, #0x11
	adds r0, r7, r1
	movs r2, #0x00
	strb r2, [r0, #0x00]
	b _0810A77A
_0810A720: .4byte 0x02039B84
_0810A724: .4byte 0x09EF9E0C
_0810A728: .4byte 0x09A3DF0C
_0810A72C: .4byte 0xFFFFF800
_0810A730: .4byte 0x000002EB
_0810A734: .4byte 0x0000FFFF
_0810A738: .4byte 0x09A3DEFC
_0810A73C: .4byte 0x00000400
_0810A740: .4byte 0x00000000
_0810A744: .4byte 0xFFFFF000
_0810A748: .4byte 0x09D34A74
_0810A74C: .4byte 0x09CB84B4
_0810A750: .4byte 0x09C448D2
_0810A754: .4byte 0x09D693D4
_0810A758: .4byte 0x08F69BC4
_0810A75C:
	movs r0, #0x07
	strh r0, [r7, #0x00]
	ldr r0, _0810A834 @ =0x00034BC0
	ldr r3, [sp, #0x01C]
	str r0, [r3, #0x00]
	movs r1, #0x01
	ldr r0, [sp, #0x018]
	strb r1, [r0, #0x00]
	ldr r2, _0810A838 @ =0x000002ED
	adds r0, r7, r2
	strb r1, [r0, #0x00]
	adds r0, r7, #0x0
	movs r1, #0x0C
	bl func_08109EF8
_0810A77A:
	ldr r0, _0810A83C @ =0x01FFFFFF
	ldr r3, [sp, #0x014]
	cmp r3, r0
	bgt _0810A7DC
	movs r2, #0xB8
	lsls r2, r2, #0x08
	movs r5, #0x9C
	lsls r5, r5, #0x09
	ldr r4, _0810A840 @ =0xFFFFF800
	str r4, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	adds r3, r5, #0x0
	bl func_0810A4CC
	movs r2, #0x8C
	lsls r2, r2, #0x09
	str r4, [sp, #0x000]
	movs r0, #0x01
	str r0, [sp, #0x004]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	adds r3, r5, #0x0
	bl func_0810A4CC
	movs r2, #0xB0
	lsls r2, r2, #0x08
	movs r5, #0xB8
	lsls r5, r5, #0x09
	str r4, [sp, #0x000]
	movs r0, #0x02
	str r0, [sp, #0x004]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	adds r3, r5, #0x0
	bl func_0810A4CC
	movs r2, #0x88
	lsls r2, r2, #0x09
	str r4, [sp, #0x000]
	movs r0, #0x03
	str r0, [sp, #0x004]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	adds r3, r5, #0x0
	bl func_0810A4CC
_0810A7DC:
	movs r1, #0xB5
	lsls r1, r1, #0x02
	adds r0, r7, r1
	ldr r0, [r0, #0x00]
	add r2, sp, #0x00C
	add r3, sp, #0x010
	add r1, sp, #0x008
	bl func_0810B7E8
	ldr r0, [sp, #0x008]
	ldr r1, [sp, #0x00C]
	ldr r2, [sp, #0x010]
	ldr r3, _0810A844 @ =0xFFFFFC00
	adds r2, r2, r3
	bl func_0801BCC0
	adds r0, r7, #0x0
	ldr r1, [sp, #0x014]
	bl func_0810A51C
	ldr r0, _0810A848 @ =0x02039B84
	ldr r2, [r0, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xCC
	ldr r0, [r7, #0x58]
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [r7, #0x5C]
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [r7, #0x60]
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, _0810A84C @ =0x0000FFF6
	strh r0, [r1, #0x00]
	add sp, #0x020
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0810A834: .4byte 0x00034BC0
_0810A838: .4byte 0x000002ED
_0810A83C: .4byte 0x01FFFFFF
_0810A840: .4byte 0xFFFFF800
_0810A844: .4byte 0xFFFFFC00
_0810A848: .4byte 0x02039B84
_0810A84C: .4byte 0x0000FFF6
.syntax divided
