.syntax unified
	.align 2, 0
	.global mode_sio_dbg_flg_0
	.thumb
	.thumb_func
	.type mode_sio_dbg_flg_0, %function
mode_sio_dbg_flg_0: @ 080C703C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	bl func_08004DB0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x0F
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x00
	bl func_08004FC8
	movs r1, #0xA8
	lsls r1, r1, #0x07
	movs r2, #0xA0
	lsls r2, r2, #0x03
	movs r0, #0x00
	bl func_0805FA8C
	ldr r1, _080C7140 @ =0x08128304
	movs r0, #0x00
	movs r2, #0x20
	movs r3, #0x0F
	bl func_0805FA60
	ldr r1, _080C7144 @ =0x02034CF4
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r3, _080C7148 @ =0x0961A9C8
	movs r0, #0x08
	movs r1, #0x24
	movs r2, #0x02
	bl func_0805FCB0
	ldr r4, _080C714C @ =0x02034CF5
	movs r0, #0x05
	strb r0, [r4, #0x00]
	ldr r3, _080C7150 @ =0x0961A9CC
	movs r0, #0x0C
	movs r1, #0x12
	movs r2, #0x02
	bl func_0805FCB0
	movs r5, #0x00
	movs r0, #0x00
	ldsb r0, [r4, r0]
	cmp r5, r0
	bge _080C70C6
	ldr r6, _080C7154 @ =0x09EF34F0
	movs r4, #0x90
	lsls r4, r4, #0x16
_080C70A6:
	lsrs r1, r4, #0x18
	ldm r6!, {r3}
	movs r0, #0x14
	movs r2, #0x02
	bl func_0805FCB0
	movs r0, #0x90
	lsls r0, r0, #0x14
	adds r4, r4, r0
	adds r5, #0x01
	ldr r0, _080C714C @ =0x02034CF5
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r5, r0
	blt _080C70A6
_080C70C6:
	ldr r1, _080C7158 @ =0x0203C3C8
	movs r0, #0x32
	strh r0, [r1, #0x00]
	ldr r4, _080C715C @ =0x0203C3CC
	movs r1, #0xFA
	lsls r1, r1, #0x01
	adds r0, r1, #0x0
	strh r0, [r4, #0x00]
	ldr r5, _080C7160 @ =0x0203C3D0
	strh r0, [r5, #0x00]
	ldr r6, _080C7164 @ =0x0203C3C4
	movs r0, #0x00
	strb r0, [r6, #0x00]
	ldr r1, _080C7168 @ =0x0203C3D4
	mov r8, r1
	strb r0, [r1, #0x00]
	movs r0, #0x64
	movs r1, #0x24
	movs r2, #0x02
	movs r3, #0x32
	bl func_0805FC04
	ldrh r3, [r4, #0x00]
	movs r0, #0x64
	movs r1, #0x2D
	movs r2, #0x02
	bl func_0805FC04
	ldrh r3, [r5, #0x00]
	movs r0, #0x64
	movs r1, #0x36
	movs r2, #0x02
	bl func_0805FC04
	ldr r4, _080C716C @ =0x09EF3504
	movs r0, #0x00
	ldsb r0, [r6, r0]
	lsls r0, r0, #0x02
	adds r0, r0, r4
	ldr r3, [r0, #0x00]
	movs r0, #0x64
	movs r1, #0x3F
	movs r2, #0x02
	bl func_0805FCB0
	mov r1, r8
	movs r0, #0x00
	ldsb r0, [r1, r0]
	lsls r0, r0, #0x02
	adds r0, r0, r4
	ldr r3, [r0, #0x00]
	movs r0, #0x64
	movs r1, #0x48
	movs r2, #0x02
	bl func_0805FCB0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080C7140: .4byte 0x08128304
_080C7144: .4byte 0x02034CF4
_080C7148: .4byte 0x0961A9C8
_080C714C: .4byte 0x02034CF5
_080C7150: .4byte 0x0961A9CC
_080C7154: .4byte 0x09EF34F0
_080C7158: .4byte 0x0203C3C8
_080C715C: .4byte 0x0203C3CC
_080C7160: .4byte 0x0203C3D0
_080C7164: .4byte 0x0203C3C4
_080C7168: .4byte 0x0203C3D4
_080C716C: .4byte 0x09EF3504
.syntax divided
